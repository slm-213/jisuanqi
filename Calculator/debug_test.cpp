#include <iostream>
#include <string>
#include "expression_evaluator.h"

void debugExpression(const std::string& expression) {
    std::cout << "测试表达式: " << expression << std::endl;
    
    ExpressionEvaluator evaluator;
    try {
        double result = evaluator.evaluate(expression);
        std::cout << "结果: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    std::cout << "---" << std::endl;
}

int main() {
    // 逐步测试
    debugExpression("1");
    debugExpression("1+2");
    debugExpression("1.5");
    debugExpression("1.5+2.3");
    debugExpression("(1+2)");
    debugExpression("3*(1+2)");
    debugExpression("11.2+3*(5.1-0.5)");
    
    return 0;
}
