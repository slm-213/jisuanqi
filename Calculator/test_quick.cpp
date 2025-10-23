#include <iostream>
#include <string>
#include "expression_evaluator.h"

int main() {
    ExpressionEvaluator evaluator;
    
    // 测试基本功能
    std::cout << "测试基本功能:" << std::endl;
    
    try {
        double result1 = evaluator.evaluate("1+2");
        std::cout << "1+2 = " << result1 << " (期望: 3)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    try {
        double result2 = evaluator.evaluate("2*3");
        std::cout << "2*3 = " << result2 << " (期望: 6)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    try {
        double result3 = evaluator.evaluate("(1+2)*3");
        std::cout << "(1+2)*3 = " << result3 << " (期望: 9)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    // 测试隐式乘号
    std::cout << "\n测试隐式乘号:" << std::endl;
    
    try {
        double result4 = evaluator.evaluate("2(3+4)");
        std::cout << "2(3+4) = " << result4 << " (期望: 14)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    try {
        double result5 = evaluator.evaluate("1+(-2)(2+3)");
        std::cout << "1+(-2)(2+3) = " << result5 << " (期望: -9)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    return 0;
}
