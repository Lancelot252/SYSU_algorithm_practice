#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 深度优先搜索（DFS）函数，非递归实现
void DFS(int v, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& start, vector<int>& finish, int& time) {
    stack<int> s;
    s.push(v);
    while (!s.empty()) {
        int node = s.top();
        if (!visited[node]) {
            visited[node] = true; // 标记节点为已访问
            start[node] = ++time; // 记录节点的开始时间
        }
        bool allVisited = true;
        for (int u : adj[node]) {
            if (!visited[u]) {
                s.push(u); // 将未访问的邻接节点压入栈中
                allVisited = false;
                break;
            }
        }
        if (allVisited) {
            s.pop(); // 如果所有邻接节点都已访问，弹出当前节点
            finish[node] = ++time; // 记录节点的结束时间
        }
    }
}

int main() {
    int t;
    cin >> t; // 读取测试用例数量
    while (t--) {
        int n, m;
        cin >> n >> m; // 读取节点数和边数
        vector<vector<int>> adj(n + 1); // 邻接表
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v; // 读取每条边
            adj[u].push_back(v); // 添加边到邻接表
            adj[v].push_back(u); // 无向图，双向添加
        }
        for (int i = 1; i <= n; ++i) {
            sort(adj[i].begin(), adj[i].end()); // 对邻接表进行排序
        }
        vector<bool> visited(n + 1, false); // 访问标记数组
        vector<int> start(n + 1, 0), finish(n + 1, 0); // 开始和结束时间数组
        int time = 0; // 时间计数器
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                DFS(i, adj, visited, start, finish, time); // 对未访问的节点进行DFS
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << i << ":" << start[i] << "-" << finish[i] << endl; // 输出每个节点的开始和结束时间
        }
        cout << "---" << endl; // 每个测试用例结束后输出分隔符
    }
    return 0;
}
