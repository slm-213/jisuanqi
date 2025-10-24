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
                return 0;
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
                if (std::abs(b) < 1e-10) {//绝对值小于10的负10
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
               getPriority(operatorStack.peek()) >= getPriority(op)) {//当栈不为空、栈顶不是左括号且栈顶操作符优先级更高时，执行运算
            
            if (operandStack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            
            double b = operandStack.pop();//先弹出b
            double a = operandStack.pop();
            char currentOp = operatorStack.pop();//弹出栈顶的操作符
            
            double result = calculate(a, b, currentOp);//结果入栈
            operandStack.push(result);
        }
        operatorStack.push(op);
    }
    
    // 处理右括号
    void processRightParenthesis() {
        while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {//遇到右括号
            if (operandStack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            
            double b = operandStack.pop();//弹出b
            double a = operandStack.pop();
            char op = operatorStack.pop();//弹出栈顶的操作符
            
            double result = calculate(a, b, op);//结果入栈
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
            
            double b = operandStack.pop();//弹出b
            double a = operandStack.pop();
            char op = operatorStack.pop();//弹出栈顶操作符
            
            double result = calculate(a, b, op);
            operandStack.push(result);
        }
    }
    
    // 预处理表达式，插入隐式乘号
    std::string preprocessExpression(const std::string& expression) const {
        std::string result;
        result.reserve(expression.length() * 2);//预留空间
        
        for (size_t i = 0; i < expression.length(); ++i) {
            char c = expression[i];//取出当前字符
            result += c;//将当前字符添加到字符串
            
            // 检查是否需要插入隐式乘号
            if (i < expression.length() - 1) {//确保索引不是最后一个字符
                char next = expression[i + 1];//获取当前字符的下一个字符
                
                //数字后跟左括号
                if (std::isdigit(c) && next == '(') {
                    result += '*';
                }
                //右括号后跟数字
                else if (c == ')' && std::isdigit(next)) {
                    result += '*';
                }
                //右括号后跟左括号
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
        
        size_t i = 0;
        while (i < processedExpression.length()) {//遍历预处理后的表达式字符串
            char c = processedExpression[i];
            
            if (std::isspace(c)) {//跳过空格
                i++;
                continue;
            }
            
            if (std::isdigit(c) || c == '.') {
                // 读取数字
                std::string numStr;//创建临时变量
                while (i < processedExpression.length() && 
                       (std::isdigit(processedExpression[i]) || processedExpression[i] == '.')) {//0-9或者小数点而且不能越界
                    numStr += processedExpression[i];//将当前字符添加到数字字符串中
                    i++;
                }
                
                // 验证数字格式
                if (numStr.empty() || numStr == ".") {
                    throw std::runtime_error("Invalid number format");
                }
                
                try {//转换成double压入栈
                    double num = std::stod(numStr);//将数字字符串转换为double类型的浮点数
                    operandStack.push(num);//压入栈
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
            else if (c == '+' || c == '-' || c == '*' || c == '/') {//处理运算符入口
                // 检查是否为负号（一元操作符）
                if (c == '-' && (operandStack.isEmpty() || 
                    (!operatorStack.isEmpty() && operatorStack.peek() == '('))) {//判断是-，数栈为空必然是负号，非空且栈顶为左括号属于负号
                    // 这是一个负号，不是减号
                    i++;
                    if (i >= processedExpression.length()) {
                        throw std::runtime_error("Invalid expression");
                    }
                    
                    // 读取负数
                    std::string numStr = "-";
                    while (i < processedExpression.length() && 
                           (std::isdigit(processedExpression[i]) || processedExpression[i] == '.')) {//索引不越界且是数或小数
                        numStr += processedExpression[i];//是将当前遍历到的字符追加到数字字符串numStr中
                        i++;
                    }
                    
                    try {//转换成double压入栈
                        double num = std::stod(numStr);
                        operandStack.push(num);
                    } catch (const std::exception&) {
                        throw std::runtime_error("Invalid number format");
                    }
                } else {
                    // 这是普通的二元操作符
                    processOperator(c);
                    i++;
                }
            }
            else {
                throw std::runtime_error("Invalid character in expression");
            }
        }
        
        // 完成剩余运算
        finishCalculation();
        
        if (operandStack.size() != 1) {
            throw std::runtime_error("Invalid expression");
        }
        
        return operandStack.peek();
    }
};

#endif // EXPRESSION_EVALUATOR_H
