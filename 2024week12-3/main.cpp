#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 霍夫曼树节点结构
struct Node {
    int freq;
    char ch;
    Node* left;
    Node* right;
    
    Node(int f, char c) : freq(f), ch(c), left(nullptr), right(nullptr) {}
};

// 优先队列比较函数
struct CompareNodes {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// 计算深度和的递归函数
long long calculateDepthSum(Node* root, int depth) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        return (long long)root->freq * depth;
    }
    return calculateDepthSum(root->left, depth + 1) + 
           calculateDepthSum(root->right, depth + 1);
}

int main() {
    int n;
    cin >> n;
    
    // 使用优先队列存储节点
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
    
    // 读入数据并创建初始节点
    for (int i = 0; i < n; i++) {
        char c;
        int freq;
        cin >> c >> freq;
        pq.push(new Node(freq, c));
    }
    
    // 构建霍夫曼树
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        
        Node* parent = new Node(left->freq + right->freq, '#');
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    
    // 计算编码位数
    Node* root = pq.top();
    cout << calculateDepthSum(root, 0) << endl;
    
    return 0;
}
