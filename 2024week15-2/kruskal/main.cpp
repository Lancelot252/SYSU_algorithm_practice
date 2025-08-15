#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 边结构体
struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // 查找根节点
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    // 合并两个集合
    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        
        // 按秩合并
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) {
                rank[rx]++;
            }
        }
    }

    // 判断是否在同一集合
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

// 使用Kruskal算法解决问题
int kruskal(int n, vector<Edge>& edges) {
    // 按边权重排序
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n);
    int maxEdge = 0;  // 记录最小生成树中的最长边
    int edgeCount = 0;  // 记录已加入的边数

    // 遍历所有边
    for (const Edge& e : edges) {
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            maxEdge = max(maxEdge, e.weight);
            edgeCount++;
            
            // 当已经形成最小生成树时退出
            if (edgeCount == n - 1) break;
        }
    }

    return maxEdge;
}

int main() {
    int T;
    cin >> T;  // 读取测试用例数量

    while (T--) {
        int N;
        cin >> N;  // 读取城镇数量

        // 读取距离矩阵并构建边列表
        vector<Edge> edges;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int distance;
                cin >> distance;
                if (i < j) {  // 只添加上三角矩阵的边，避免重复
                    edges.emplace_back(i, j, distance);
                }
            }
        }

        // 输出结果
        cout << kruskal(N, edges) << endl;
        
        // 如果不是最后一个测试用例，输出空行
        if (T > 0) cout << endl;
    }

    return 0;
}
