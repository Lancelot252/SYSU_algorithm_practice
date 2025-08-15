#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Prim算法求最小生成树
int prim(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);  // 记录顶点是否已访问
    vector<int> minEdge(n, INT_MAX); // 存储到已访问集合的最小边权值
    int maxEdge = 0;           // 最小生成树中的最长边

    minEdge[0] = 0;  // 从顶点0开始

    for (int i = 0; i < n; i++) {
        // 找到未访问顶点中距离最小的
        int minVertex = -1;
        int minDist = INT_MAX;
        
        for (int j = 0; j < n; j++) {
            if (!visited[j] && minEdge[j] < minDist) {
                minDist = minEdge[j];
                minVertex = j;
            }
        }

        visited[minVertex] = true;
        
        // 更新当前最长边
        if (i > 0) {  // 跳过第一个顶点
            maxEdge = max(maxEdge, minDist);
        }

        // 更新其他未访问顶点的最小边权值
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[minVertex][j] < minEdge[j]) {
                minEdge[j] = graph[minVertex][j];
            }
        }
    }

    return maxEdge;
}

int main() {
    int T;
    cin >> T;  // 读取测试用例数量

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;  // 读取城镇数量

        // 读取距离矩阵
        vector<vector<int>> graph(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> graph[i][j];
            }
        }

        // 计算并输出结果
        int result = prim(graph, N);
        cout << result << endl;

        // 如果不是最后一个测试用例，输出空行
        if (t < T - 1) {
            cout << endl;
        }
    }

    return 0;
}
