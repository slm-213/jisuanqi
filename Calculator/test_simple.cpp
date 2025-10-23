#include <iostream>
#include <string>
#include "expression_evaluator.h"

int main() {
    ExpressionEvaluator evaluator;
    
    // 测试问题表达式
    std::string expression = "11.2+3*(5.1-0.5)";
    
    try {
        double result = evaluator.evaluate(expression);
        std::cout << "表达式: " << expression << std::endl;
        std::cout << "结果: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    return 0;
}
