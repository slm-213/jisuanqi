#include <iostream>
#include <string>
#include "expression_evaluator.h"

void testExpression(const std::string& expression, const std::string& description) {
    ExpressionEvaluator evaluator;
    try {
        double result = evaluator.evaluate(expression);
        std::cout << "✓ " << description << std::endl;
        std::cout << "  表达式: " << expression << std::endl;
        std::cout << "  结果: " << result << std::endl;
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✗ " << description << std::endl;
        std::cout << "  表达式: " << expression << std::endl;
        std::cout << "  错误: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "=== 计算器测试用例 ===" << std::endl;
    std::cout << std::endl;
    
    // 正常测试用例
    std::cout << "--- 正常测试用例 ---" << std::endl;
    testExpression("6 * (2 + 3) / 5 + 7", "基本四则运算和括号");
    testExpression("11.2+3*(5.1-0.5)", "小数运算");
    testExpression("1+2*3", "运算符优先级");
    testExpression("(1+2)*3", "括号优先级");
    testExpression("10/2", "除法运算");
    testExpression("3.14*2", "小数乘法");
    
    std::cout << "--- 错误测试用例 ---" << std::endl;
    testExpression("1.5.5.", "多个小数点");
    testExpression("1++2", "连续操作符");
    testExpression("1/0", "除零错误");
    testExpression(")", "不匹配的右括号");
    testExpression("*", "单独的操作符");
    testExpression("( )", "空括号");
    testExpression("1+(-2)(2+3)", "负数运算");
    
    std::cout << "--- 边界测试用例 ---" << std::endl;
    testExpression("0", "零值");
    testExpression("1", "单位数");
    testExpression("1+1", "简单加法");
    testExpression("2*3+4", "混合运算");
    testExpression("(1+2)*(3+4)", "复杂括号");
    
    return 0;
}
