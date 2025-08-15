#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 检查有向图是否为DAG（有向无环图）
bool if_dag(vector<vector<int>>& adj, vector<bool>& visited, int n) {
    queue<int> s;
    vector<int> indegree(n + 1, 0); // 记录每个节点的入度

    // 计算每个节点的入度
    for (int i = 1; i <= n; ++i) {
        for (int j : adj[i]) {
            indegree[j]++;
        }
    }

    // 将所有入度为0的节点入队
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            s.push(i);
        }
    }

    // 拓扑排序
    while (!s.empty()) {
        int p = s.front();
        s.pop();
        if (!visited[p]) {
            visited[p] = true;
            for (int i : adj[p]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    s.push(i);
                }
            }
        }
    }

    // 检查是否所有节点的入度都为0
    for (int i = 1; i <= n; ++i) {
        if (indegree[i]) {
            return false; // 如果有节点的入度不为0，则不是DAG
        }
    }

    return true; // 所有节点的入度都为0，则是DAG
}

int main() {
    int n, m;
    cin >> n >> m; // 输入节点数和边数
    vector<vector<int>> adj(n + 1); // 邻接表表示图
    vector<bool> visited(n + 1, false); // 记录节点是否被访问

    // 输入边的信息
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // 添加有向边
    }

    // 输出图是否为DAG
    cout << if_dag(adj, visited, n) << endl;
    return 0;
}