#include <iostream>
#include <string>
#include "expression_evaluator.h"

int main() {
    ExpressionEvaluator evaluator;
    
    // 测试隐式乘号
    std::string test1 = "1+(-2)(2+3)";
    std::cout << "测试表达式: " << test1 << std::endl;
    
    try {
        double result = evaluator.evaluate(test1);
        std::cout << "计算结果: " << result << std::endl;
        std::cout << "期望结果: -9" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    return 0;
}
