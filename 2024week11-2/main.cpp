#include <iostream>
#include <vector>
using namespace std;

// 并查集类，用于处理连通性问题
class UnionFind {
public:
    // 构造函数，初始化并查集
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // 每个节点的父节点初始化为自身
        }
    }

    // 查找操作，带路径压缩
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // 递归查找父节点，并进行路径压缩
        }
        return parent[u];
    }

    // 合并操作，按秩合并
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU; // 将秩低的树合并到秩高的树上
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++; // 如果秩相同，合并后树的秩加一
            }
        }
    }

private:
    vector<int> parent; // 存储每个节点的父节点
    vector<int> rank;   // 存储每个节点的秩（树的高度）
};

int main() {
    int T;
    cin >> T; // 读取测试用例数量
    while (T--) {
        int n, m;
        cin >> n >> m; // 读取节点数和边数
        UnionFind uf(n + 1); // 初始化并查集
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v; // 读取每条边的两个端点
            uf.unite(u, v); // 合并两个端点所在的集合
        }
        int q;
        cin >> q; // 读取查询数量
        for (int i = 0; i < q; ++i) {
            int u, v;
            cin >> u >> v; // 读取每个查询的两个节点
            if (uf.find(u) == uf.find(v)) {
                cout << "Yes" << endl; // 如果两个节点在同一个集合中，输出Yes
            } else {
                cout << "No" << endl; // 否则输出No
            }
        }
        if (T > 0) {
            cout << endl; // 如果还有测试用例，输出一个空行分隔
        }
    }
    return 0;
}