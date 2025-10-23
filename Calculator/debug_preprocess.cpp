#include <iostream>
#include <string>
#include "expression_evaluator.h"

int main() {
    // 测试预处理函数
    std::string test = "1+(-2)(2+3)";
    std::cout << "原始表达式: " << test << std::endl;
    
    ExpressionEvaluator evaluator;
    
    // 我们需要访问预处理函数，但它是私有的
    // 让我们直接测试计算
    try {
        double result = evaluator.evaluate(test);
        std::cout << "计算结果: " << result << std::endl;
        std::cout << "期望结果: -9" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    return 0;
}
