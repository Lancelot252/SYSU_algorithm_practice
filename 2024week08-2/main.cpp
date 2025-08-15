#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <random>
#include <algorithm>

// 直接包含头文件，使用 query 的声明
#include "query.h"

static std::string gen_rand_str(std::mt19937 &rng, int len) {
    static const char letters[] = "abcdefghijklmnopqrstuvwxyz";
    std::uniform_int_distribution<int> dist(0, 25);
    std::string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i) s.push_back(letters[dist(rng)]);
    return s;
}

static void run_test(const std::vector<std::string> &A, const std::vector<std::string> &B, const std::string &title) {
    std::cout << "==== " << title << " ====\n";
    // 计算期望输出
    std::unordered_set<std::string> setA(A.begin(), A.end());
    std::cout << "Expected:\n";
    for (const auto &b : B) {
        if (setA.find(b) != setA.end()) std::cout << b << '\n';
    }
    std::cout << "Actual:\n";
    // 调用被测函数
    std::vector<std::string> copyA = A; // 保证连续内存
    std::vector<std::string> copyB = B;
    query(copyA.data(), static_cast<int>(copyA.size()), copyB.data(), static_cast<int>(copyB.size()));
    std::cout << "----\n\n";
}

int main() {
    // 示例数据（题目提示）
    std::vector<std::string> A1 = {"ABC", "CD", "D"};
    std::vector<std::string> B1 = {"A", "CD", "BC", "ABC"};
    run_test(A1, B1, "Sample Test");

    // 小规模自定义测试
    std::vector<std::string> A2 = {"apple", "banana", "orange", "grape"};
    std::vector<std::string> B2 = {"banana", "pear", "grape", "apple", "melon"};
    run_test(A2, B2, "Small Custom Test");

    // 全匹配测试
    std::vector<std::string> A3 = {"s1", "s2", "s3"};
    std::vector<std::string> B3 = {"s1", "s2", "s3"};
    run_test(A3, B3, "All Match Test");

    // 无匹配测试
    std::vector<std::string> A4 = {"x", "y", "z"};
    std::vector<std::string> B4 = {"a", "b", "c"};
    run_test(A4, B4, "No Match Test");

    // 随机大规模测试（可调大小）
    std::mt19937 rng(20250302); // 固定种子，保证可复现
    const int n = 1000;
    const int m = 1500;
    std::unordered_set<std::string> aset;
    std::vector<std::string> A5;
    A5.reserve(n);
    while ((int)A5.size() < n) {
        std::string s = gen_rand_str(rng, 6);
        if (aset.insert(s).second) A5.push_back(s);
    }
    // 构造 B: 包含部分来自 A 和部分随机不存在的字符串
    std::vector<std::string> B5;
    B5.reserve(m);
    // 先加入一些来自 A
    for (int i = 0; i < m / 3; ++i) B5.push_back(A5[i * 2 % n]);
    // 再加入随机可能存在或不存在
    for (int i = (int)B5.size(); i < m; ++i) {
        if (i % 4 == 0) B5.push_back(A5[(i * 7) % n]);
        else B5.push_back(gen_rand_str(rng, 6));
    }
    run_test(A5, B5, "Large Random Test");

    return 0;
}