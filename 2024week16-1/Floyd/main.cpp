#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;



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

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(graph[i][k] != INF && graph[k][j] != INF){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        int res = graph[a][b];
        if(res == INF){
            res = -1;
        }
        cout << res << endl;
    }
}