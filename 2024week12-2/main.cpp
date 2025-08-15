#include <iostream>
#include <vector>
using namespace std;

// 并查集结构
class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // 路径压缩
        }
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return false; // 检测到环
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

bool isTree(int n, int m, vector<pair<int, int>>& edges) {
    if (m != n - 1) return false; // 树必须有 n-1 条边

    UnionFind uf(n + 1);
    for (auto& edge : edges) {
        if (!uf.unionSets(edge.first, edge.second)) return false; // 检测到环
    }

    return true; // 没有检测到环且边数为 n-1
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }
        if (isTree(n, m, edges)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
