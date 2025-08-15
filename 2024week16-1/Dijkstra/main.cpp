#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int shortest(vector<vector<int>>& graph, int n, int start, int end) {
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    dist[start] = 0;
    
    // 使用pair存储距离和顶点信息，first是距离，second是顶点编号
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] == INF) continue;
            if (!visited[v] && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }
    if(dist[end] == INF) return -1;
    return dist[end];
}

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
    for (int i = 0; i <= N; i++) {
        graph[i][i] = 0;
    }
    for (int i = 0; i < K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b],c);
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        int res = shortest(graph, N, a, b);
        cout << res << endl;
    }
}