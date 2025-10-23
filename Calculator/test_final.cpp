#include <iostream>
#include <string>
#include "expression_evaluator.h"

int main() {
    ExpressionEvaluator evaluator;
    
    std::cout << "=== 测试隐式乘号功能 ===" << std::endl;
    
    // 测试用例
    std::string tests[] = {
        "1+(-2)(2+3)",     // 应该 = -9
        "2(3+4)",          // 应该 = 14
        "(1+2)(3+4)",      // 应该 = 21
        "6 * (2 + 3) / 5 + 7",  // 应该 = 13
        "11.2+3*(5.1-0.5)" // 应该 = 25
    };
    
    double expected[] = {-9, 14, 21, 13, 25};
    
    for (int i = 0; i < 5; i++) {
        std::cout << "测试 " << (i+1) << ": " << tests[i] << std::endl;
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
        std::cout << "---" << std::endl;
    }
    
    return 0;
}
