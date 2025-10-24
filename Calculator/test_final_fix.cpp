#include <iostream>
#include <string>
#include "expression_evaluator.h"

int main() {
    ExpressionEvaluator evaluator;
    
    std::cout << "=== 测试修复后的表达式求值器 ===" << std::endl;
    
    // 测试用例
    std::string tests[] = {
        "1+2",              // 基本加法
        "2*3",              // 基本乘法
        "(1+2)*3",          // 括号
        "2(3+4)",           // 隐式乘号
        "1+(-2)(2+3)",      // 复杂隐式乘号
        "6 * (2 + 3) / 5 + 7"  // 复杂表达式
    };
    
    double expected[] = {3, 6, 9, 14, -9, 13};
    
    for (int i = 0; i < 6; i++) {
        std::cout << "\n测试 " << (i+1) << ": " << tests[i] << std::endl;
        try {
            double result = evaluator.evaluate(tests[i]);
            std::cout << "结果: " << result << std::endl;
            std::cout << "期望: " << expected[i] << std::endl;
            if (abs(result - expected[i]) < 1e-10) {
                std::cout << "✓ 通过" << std::endl;
            } else {
                std::cout << "✗ 失败" << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "错误: " << e.what() << std::endl;
        }
    }
    
    return 0;
}



