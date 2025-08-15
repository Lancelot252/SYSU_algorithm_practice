#include <iostream>
#include <vector>
using namespace std;

// 深度优先搜索函数，用于遍历图
void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true; // 标记当前节点为已访问
    for (int u : adj[v]) { // 遍历当前节点的所有邻接节点
        if (!visited[u]) { // 如果邻接节点未被访问，递归调用dfs
            dfs(u, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // 输入节点数和边数
    vector<vector<int>> adj(n + 1); // 邻接表表示的图
    vector<bool> visited(n + 1, false); // 访问标记数组

    for (int i = 0; i < m; ++i) {
        int v, y;
        cin >> v >> y; // 输入每条边的两个节点
        adj[v].push_back(y); // 将边加入邻接表
        adj[y].push_back(v); // 无向图需要双向添加
    }

    int connectedComponents = 0; // 连通分量计数
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) { // 如果节点未被访问，说明是一个新的连通分量
            dfs(i, adj, visited); // 进行深度优先搜索
            ++connectedComponents; // 连通分量计数加一
        }
    }

    cout << connectedComponents << endl; // 输出连通分量的数量
    return 0;
}
