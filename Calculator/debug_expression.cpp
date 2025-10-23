#include <iostream>
#include <string>
#include "expression_evaluator.h"

int main() {
    ExpressionEvaluator evaluator;
    
    // 测试表达式
    std::string test = "1+(-2)(2+3)";
    std::cout << "原始表达式: " << test << std::endl;
    
    try {
        double result = evaluator.evaluate(test);
        std::cout << "结果: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    // 测试简单表达式
    std::cout << "\n测试简单表达式:" << std::endl;
    try {
        double result = evaluator.evaluate("1+2");
        std::cout << "1+2 = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    return 0;
}
