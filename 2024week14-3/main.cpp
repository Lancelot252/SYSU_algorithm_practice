#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void topo(vector<vector<int>>& adj, int n) {
    // 使用小顶堆来存储入度为0的节点，保证输出的节点按升序排列
    priority_queue<int, vector<int>, greater<int>> s;
    vector<int> indegree(n + 1, 0);
    // 计算每个节点的入度
    for (int i = 1; i <= n; ++i) {
        for (int j : adj[i]) {
            indegree[j]++;
        }
    }
    // 将入度为0的节点加入堆中
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            s.push(i);
        }
    }

    while (!s.empty()) {
        int p = s.top();
        cout << p << " "; // 输出当前节点
        s.pop();
        
        // 将当前节点的邻接点入度减1，如果入度为0，加入堆中
        for (int i : adj[p]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                s.push(i);
            }
        }
    }
}

int main(){
    int num;
    cin>>num; // 读取测试用例数量
    for(int t=0; t<num; t++){
        int n,m;
        cin>>n>>m; // 读取节点数和边数
        vector<vector<int>> adj(n+1);
        vector<bool> visited(n+1,false);
        // 构建邻接表
        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b; // 读取边的信息
            adj[a].push_back(b);
        }
        topo(adj,n); // 调用拓扑排序函数
        cout<<endl;
    }
    
    return 0;
}