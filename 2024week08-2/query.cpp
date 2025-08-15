#include <iostream>
#include <unordered_set>
#include <string>

void query(std::string A[], int n, std::string B[], int m) {
    // 创建一个哈希集合，将集合A中的字符串加入集合
    std::unordered_set<std::string> setA(A, A + n);

    // 遍历集合B，检查每个字符串是否在集合A中
    for (int i = 0; i < m; ++i) {
        if (setA.find(B[i]) != setA.end()) {
            // 如果找到，输出该字符串
            std::cout << B[i] << std::endl;
        }
    }
}
