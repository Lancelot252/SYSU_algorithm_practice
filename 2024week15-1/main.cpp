#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义边结构体
struct Edge {
    int u, v, weight;
    // 重载小于运算符，用于按权重从大到小排序
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

// 查找并查集的根节点
int find(vector<int>& parent, int u) {
    if (parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

// 合并两个集合
void unite(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Kruskal 算法求最大生成树的权重和
int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // 按权重从大到小排序
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    int maxWeightSum = 0;
    for (const auto& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            unite(parent, rank, edge.u, edge.v);
            maxWeightSum += edge.weight;// 将边的权重加入最大生成树的权重和
        }
    }
    return maxWeightSum;
}

int main() {
    int t;
    cin >> t; // 读取测试用例数目
    while (t--) {
        int n, m;
        cin >> n >> m; // 读取顶点数和边数
        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].weight; // 读取每条边的信息
        }
        cout << kruskal(n, edges) << endl; // 输出最大生成森林的值
    }
    return 0;
}
