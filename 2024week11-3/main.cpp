#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int MAX_N = 1000; // Define MAX_N with an appropriate value

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
    UnionFind uf(MAX_N + 1);
    int x, y;
    while (cin >> x >> y) {
        if (x != y && uf.find(x) != uf.find(y)) {
            cout << x << " " << y << endl;
            uf.unite(x, y);
        }
    }
    return 0;
}
