#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 定义哈夫曼树节点
struct Node {
    char ch;         // 字符
    int freq;        // 频率
    Node *left;      // 左子节点
    Node *right;     // 右子节点
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// 自定义比较函数，用于优先队列
struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq) {
            return a->ch < b->ch; // 频率相同时，字符大的优先
        }
        return a->freq > b->freq; // 频率小的优先
    }
};

// 后序遍历哈夫曼树，输出字符
void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    if (!root->left && !root->right) { // 叶子节点
        cout << root->ch << endl;
    }
}

int main() {
    int K;
    cin >> K;
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // 读取输入字符和频率
    for (int i = 0; i < K; ++i) {
        char ch;
        int freq;
        cin >> ch >> freq;
        pq.push(new Node(ch, freq));
    }

    // 构建哈夫曼树
    while (pq.size() > 1) {
        Node* node1 = pq.top(); pq.pop();
        Node* node2 = pq.top(); pq.pop();

        Node* leftChild;
        Node* rightChild;

        if (node1->freq < node2->freq) {
            // 频率小的在右边
            rightChild = node1;
            leftChild = node2;
        } else if (node1->freq > node2->freq) {
            // 频率大的在左边
            leftChild = node1;
            rightChild = node2;
        } else {
            // 频率相同，比较字符
            if (node1->ch < node2->ch) {
                // 字符小的在右边
                rightChild = node1;
                leftChild = node2;
            } else {
                leftChild = node1;
                rightChild = node2;
            }
        }

        Node* parent = new Node('\0', node1->freq + node2->freq);
        parent->left = leftChild;
        parent->right = rightChild;

        pq.push(parent);
    }

    // 后序遍历输出结果
    Node* root = pq.top();
    postOrder(root);

    return 0;
}
