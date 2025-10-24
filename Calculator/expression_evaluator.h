//核心计算模块
#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include "stack.h"
#include <string>
#include <stdexcept>
#include <cmath>

class ExpressionEvaluator {
private:
    Stack<double> operandStack;  // 操作数栈
    Stack<char> operatorStack;   // 操作符栈
    
    // 获取操作符优先级
    int getPriority(char op) const {
        switch (op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '(':
                return 0;//保证左括号不被弹出
            default:
                return -1;
        }
    }
    
    // 执行运算
    double calculate(double a, double b, char op) const {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (std::abs(b) < 1e-10) {//除数的绝对值小于10的负10次方
                    throw std::runtime_error("Division by zero");
                }
                return a / b;
            default:
                throw std::runtime_error("Invalid operator");
        }
    }
    
    // 处理操作符
    void processOperator(char op) {
        while (!operatorStack.isEmpty() && 
               operatorStack.peek() != '(' && 
               getPriority(operatorStack.peek()) >= getPriority(op)) {// 当运算符栈不为空，且栈顶不是左括号，且栈顶运算符优先级 ≥ 当前运算符时
            
            if (operandStack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            
            double b = operandStack.pop();// 弹出操作数栈的两个元素，b后入栈
            double a = operandStack.pop();
            char currentOp = operatorStack.pop();//弹出运算符
            
            double result = calculate(a, b, currentOp);//计算 a currentOp b 的结果
            operandStack.push(result);//将计算结果压回操作数栈（作为新的操作数，供后续计算）
        }
        operatorStack.push(op);//循环结束后，将当前运算符 op 压入运算符栈
    }
    
    // 处理右括号
    void processRightParenthesis() {
        while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {//运算符不为空并且栈顶不是左括号
            if (operandStack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            
            double b = operandStack.pop();
            double a = operandStack.pop();
            char op = operatorStack.pop();
            
            double result = calculate(a, b, op);
            operandStack.push(result);
        }
        
        if (operatorStack.isEmpty()) {
            throw std::runtime_error("Mismatched parentheses");
        }
        operatorStack.pop(); // 移除左括号
    }
    
    // 完成剩余运算
    void finishCalculation() {
        while (!operatorStack.isEmpty()) {
            if (operandStack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            
            double b = operandStack.pop();
            double a = operandStack.pop();
            char op = operatorStack.pop();
            
            double result = calculate(a, b, op);
            operandStack.push(result);
        }
    }
    
    // 预处理表达式，插入隐式乘号
    std::string preprocessExpression(const std::string& expression) const {//返回类型为string的函数
        std::string result;//创造string对象
        result.reserve(expression.length() * 2);//提前预留好空间，防止表达式拼接位置不够
        
        for (size_t i = 0; i < expression.length(); ++i) {//从头到尾把原始表达式抄一遍到新地方
            char c = expression[i];
            result += c;
            
            // 检查是否需要插入隐式乘号
            if (i < expression.length() - 1) {
                char next = expression[i + 1];//取出当前字符后面的那个字符，判断是否隐藏乘号
                
                //数字后跟左括号
                if (std::isdigit(c) && next == '(') {//判断c是不是数字并且next是不是左括号
                    result += '*';//在结果字符串加个乘号
                }
                //右括号后跟数字
                else if (c == ')' && std::isdigit(next)) {
                    result += '*';
                }
                // 右括号后跟左括号
                else if (c == ')' && next == '(') {
                    result += '*';
                }
            }
        }
        
        return result;
    }

public:
    // 计算表达式
    double evaluate(const std::string& expression) {
        // 预处理表达式
        std::string processedExpression = preprocessExpression(expression);
        
        // 清空栈
        operandStack.clear();
        operatorStack.clear();
        
        size_t i = 0;//定义一个无符号整数变量 i 作为下标，初始化为 0
        while (i < processedExpression.length()) {//遍历每一个字符
            char c = processedExpression[i];//取出表达式中当前下标 i 对应的字符，存到变量 c
            
            if (std::isspace(c)) {//若c是空白字符
                i++;
                continue;
            }
            
            // 处理数字
            if (std::isdigit(c) || c == '.') {//c是数字或者.
                std::string numStr;//定义字符串变量存储数字字符串
                while (i < processedExpression.length() && 
                       (std::isdigit(processedExpression[i]) || processedExpression[i] == '.')) {//判断没有越界且变量是0-9或者.
                    numStr += processedExpression[i];//把当前字符拼入字符串
                    i++;
                }
                
                if (numStr.empty() || numStr == ".") {
                    throw std::runtime_error("Invalid number format");
                }
                
                try {
                    double num = std::stod(numStr);//把字符串数字转换为double类型
                    operandStack.push(num);//转换后的数字入栈
                } catch (const std::exception&) {//捕获所有标准库抛出的异常
                    throw std::runtime_error("Invalid number format");
                }
            }
            // 把负号和它后面的数字分开处理
            else if (c == '-' && (i == 0 || processedExpression[i-1] == '(' || 
                     processedExpression[i-1] == '+' || processedExpression[i-1] == '-' || 
                     processedExpression[i-1] == '*' || processedExpression[i-1] == '/')) {//如果c是-并且满足前面是其他运算符
                i++; // 跳过负号
                if (i >= processedExpression.length()) {//负号之后无东西报错
                    throw std::runtime_error("Invalid expression");
                }
                
                // 读取数字
                std::string numStr;//定义临时变量
                while (i < processedExpression.length() && 
                       (std::isdigit(processedExpression[i]) || processedExpression[i] == '.')) {//循环读取数字字符
                    numStr += processedExpression[i];//用临时变量拼接
                    i++;
                }
                
                if (numStr.empty() || numStr == ".") {
                    throw std::runtime_error("Invalid number format");
                }
                
                try {
                    double num = -std::stod(numStr);//得到负数再进行存入
                    operandStack.push(num);
                } catch (const std::exception&) {
                    throw std::runtime_error("Invalid number format");
                }
            }
            else if (c == '(') {
                operatorStack.push(c);
                i++;
            }
            else if (c == ')') {
                processRightParenthesis();
                i++;
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                processOperator(c);
                i++;
            }
            else {
                throw std::runtime_error("Invalid character in expression");
            }
        }
        
        // 完成剩余运算
        finishCalculation();
        
        if (operandStack.size() != 1) {
            throw std::runtime_error("Invalid expression");//计算完成之后大小需要为1
        }
        
        return operandStack.peek();//返回栈顶元素
    }
};

#endif // EXPRESSION_EVALUATOR_H
