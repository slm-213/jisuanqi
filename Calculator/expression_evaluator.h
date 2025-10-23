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
                if (std::abs(b) < 1e-10) {
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
               getPriority(operatorStack.peek()) >= getPriority(op)) {
            
            if (operandStack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            
            double b = operandStack.pop();
            double a = operandStack.pop();
            char currentOp = operatorStack.pop();
            
            double result = calculate(a, b, currentOp);
            operandStack.push(result);
        }
        operatorStack.push(op);
    }
    
    // 处理右括号
    void processRightParenthesis() {
        while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
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
    std::string preprocessExpression(const std::string& expression) const {
        std::string result;
        result.reserve(expression.length() * 2);
        
        for (size_t i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            result += c;
            
            // 检查是否需要插入隐式乘号
            if (i < expression.length() - 1) {
                char next = expression[i + 1];
                
                // 情况1: 数字后跟左括号，如 "2(" -> "2*("
                if (std::isdigit(c) && next == '(') {
                    result += '*';
                }
                // 情况2: 右括号后跟数字，如 ")2" -> ")*2"
                else if (c == ')' && std::isdigit(next)) {
                    result += '*';
                }
                // 情况3: 右括号后跟左括号，如 ")(" -> ")*("
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
        while (i < processedExpression.length()) {
            char c = processedExpression[i];
            
            if (std::isspace(c)) {
                i++;
                continue;
            }
            
            // 处理数字（包括负数）
            if (std::isdigit(c) || c == '.') {
                std::string numStr;
                while (i < processedExpression.length() && 
                       (std::isdigit(processedExpression[i]) || processedExpression[i] == '.')) {
                    numStr += processedExpression[i];
                    i++;
                }
                
                if (numStr.empty() || numStr == ".") {
                    throw std::runtime_error("Invalid number format");
                }
                
                try {
                    double num = std::stod(numStr);
                    operandStack.push(num);
                } catch (const std::exception&) {
                    throw std::runtime_error("Invalid number format");
                }
            }
            // 处理负数
            else if (c == '-' && (i == 0 || processedExpression[i-1] == '(' || 
                     processedExpression[i-1] == '+' || processedExpression[i-1] == '-' || 
                     processedExpression[i-1] == '*' || processedExpression[i-1] == '/')) {
                i++; // 跳过负号
                if (i >= processedExpression.length()) {
                    throw std::runtime_error("Invalid expression");
                }
                
                // 读取数字
                std::string numStr;
                while (i < processedExpression.length() && 
                       (std::isdigit(processedExpression[i]) || processedExpression[i] == '.')) {
                    numStr += processedExpression[i];
                    i++;
                }
                
                if (numStr.empty() || numStr == ".") {
                    throw std::runtime_error("Invalid number format");
                }
                
                try {
                    double num = -std::stod(numStr);
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
            throw std::runtime_error("Invalid expression");
        }
        
        return operandStack.peek();
    }
};

#endif // EXPRESSION_EVALUATOR_H
