#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1005; // 最大节点数
vector<int> adj[MAXN]; // 邻接表
bool visited[MAXN]; // 访问标记数组

// 深度优先搜索函数
void dfs(int u) {
    visited[u] = true; // 标记当前节点已访问
    for (int v : adj[u]) { // 遍历所有邻接节点
        if (!visited[v]) { // 如果邻接节点未被访问
            dfs(v); // 递归访问邻接节点
        }
    }
}

int main() {
    int T; // 测试用例数量
    cin >> T;
    while (T--) {
        int n, m; // 节点数和边数
        cin >> n >> m;
        // 重置数据
        for (int i = 1; i <= n; i++) {
            adj[i].clear(); // 清空邻接表
            visited[i] = false; // 重置访问标记
        }
        vector<int> degree(n + 1, 0); // 度数数组
        // 读入边
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // 添加边 u -> v
            adj[v].push_back(u); // 添加边 v -> u
            degree[u]++; // 增加节点 u 的度数
            degree[v]++; // 增加节点 v 的度数
        }
        // 找到第一个度大于 0 的节点作为起点
        int start = -1;
        for (int i = 1; i <= n; i++) {
            if (degree[i] > 0) {
                start = i;
                break;
            }
        }
        if (start == -1) {
            // 所有节点度为 0，输出 "Euler Circuit"
            cout << "Euler Circuit" << endl;
            continue;
        }
        // 从起点开始 DFS
        dfs(start);
        // 检查连通性
        bool isConnected = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && degree[i] > 0) { // 只检查度数大于 0 的节点
                isConnected = false;
                break;
            }
        }
        if (!isConnected) {
            cout << "Neither" << endl;
            continue;
        }
        // 统计奇数度节点数
        int oddCount = 0;
        for (int i = 1; i <= n; i++) {
            if (degree[i] % 2 != 0) {
                oddCount++;
            }
        }
        if (oddCount == 0) {
            cout << "Euler Circuit" << endl; // 所有节点度数为偶数，存在欧拉回路
        } else if (oddCount == 2) {
            cout << "Euler Path" << endl; // 恰有两个节点度数为奇数，存在欧拉路径
        } else {
            cout << "Neither" << endl; // 否则，不存在欧拉路径或欧拉回路
        }
    }
    return 0;
}
