#include <iostream>
#include <string>
#include "expression_evaluator.h"

void testImplicitMultiply(const std::string& expression, const std::string& description) {
    std::cout << "测试: " << description << std::endl;
    std::cout << "表达式: " << expression << std::endl;
    
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
    // 测试隐式乘号
    testImplicitMultiply("1+(-2)(2+3)", "括号间隐式乘号");
    testImplicitMultiply("2(3+4)", "数字后括号");
    testImplicitMultiply("(1+2)(3+4)", "括号间隐式乘号");
    testImplicitMultiply("3*2(1+1)", "混合隐式乘号");
    testImplicitMultiply("1+2*3", "正常表达式");
    testImplicitMultiply("(1+2)*3", "显式乘号");
    
    return 0;
}
