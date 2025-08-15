#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 判断是否可以从城市0到达城市N-1
bool canPostLetter(int N, int M, vector<pair<int, int>>& roads) {
    // 创建邻接表表示图
    vector<vector<int>> adj(N);
    for (const auto& road : roads) {
        adj[road.first].push_back(road.second);
    }

    // 创建访问标记数组
    vector<bool> visited(N, false);
    // 创建栈用于深度优先搜索
    stack<int> s;
    s.push(0); // 从城市0开始

    while (!s.empty()) {
        int city = s.top();
        s.pop();

        // 如果到达城市N-1，返回true
        if (city == N - 1) {
            return true;
        }

        // 如果当前城市未被访问过
        if (!visited[city]) {
            visited[city] = true; // 标记为已访问
            // 将所有未访问的邻居城市压入栈中
            for (int neighbor : adj[city]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    // 如果无法到达城市N-1，返回false
    return false;
}

int main() {
    int N, M;
    // 读取输入直到N为0
    while (cin >> N && N != 0) {
        cin >> M;
        vector<pair<int, int>> roads(M);
        // 读取所有道路信息
        for (int i = 0; i < M; ++i) {
            cin >> roads[i].first >> roads[i].second;
        }

        // 判断是否可以邮寄信件并输出结果
        if (canPostLetter(N, M, roads)) {
            cout << "I can post the letter" << endl;
        } else {
            cout << "I can't post the letter" << endl;
        }
    }
    return 0;
}
