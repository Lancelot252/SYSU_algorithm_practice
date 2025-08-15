#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义树节点结构体
struct TreeNode {
     int val; // 节点值
     TreeNode* left; // 左子节点指针
     TreeNode* right; // 右子节点指针
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // 构造函数
 };

// 添加子节点函数
void addChild(TreeNode* parent, TreeNode* child) {
    if (!parent->left) { // 如果左子节点为空，则添加到左子节点
        parent->left = child;
    } else { // 否则，添加到右子节点
        TreeNode* sibling = parent->left;
        while (sibling->right) { // 找到最右边的子节点
            sibling = sibling->right;
        }
        sibling->right = child; // 添加到最右边的子节点
    }
}

// 层次遍历函数
vector<int> levelOrderTraversal(TreeNode* root) {
    vector<int> result; // 存储遍历结果
    if (!root) return result; // 如果根节点为空，返回空结果

    queue<TreeNode*> q; // 定义队列
    q.push(root); // 根节点入队

    while (!q.empty()) { // 当队列不为空时
        TreeNode* node = q.front(); // 获取队首节点
        q.pop(); // 队首节点出队
        result.push_back(node->val); // 将节点值添加到结果中

        if (node->left) q.push(node->left); // 左子节点入队
        if (node->right) q.push(node->right); // 右子节点入队
    }

    return result; // 返回遍历结果
}

int main() {
    int n;
    cin >> n; // 输入节点数量

    vector<TreeNode*> nodes(n + 1, nullptr); // 创建节点数组
    for (int i = 1; i <= n; ++i) {
        nodes[i] = new TreeNode(i); // 初始化每个节点
    }

    for (int i = 2; i <= n; ++i) {
        int parent;
        cin >> parent; // 输入父节点编号
        addChild(nodes[parent], nodes[i]); // 添加子节点
    }

    vector<int> result = levelOrderTraversal(nodes[1]); // 获取层次遍历结果
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " "; // 输出空格分隔符
        cout << result[i]; // 输出节点值
    }
    cout << endl; // 输出换行符

    // 清理内存
    for (int i = 1; i <= n; ++i) {
        delete nodes[i]; // 删除每个节点
    }

    return 0; // 返回0表示程序执行成功
}

// struct node {
//     int parent;
//     int val;
// };

// int main() {
//     int n;
//     cin >> n;
//     vector<node> nodes(n);
//     for (int i = 0; i < n - 1; i++) {
//         cin >> nodes[i].parent;
//         nodes[i].val = i + 2;
//     }
//     cout << 1 << " ";
//     for (auto i = nodes.begin(); i != nodes.end();) {
//         if(i->val)
//         cout << i->val << " ";
//         int val=i->val;
//         int prt=i->parent;
//         auto k = nodes.begin();
//         auto j = nodes.begin();
//         nodes.erase(i);
//         for (; j != nodes.end(); j++) {
//             if (j->parent == val) {
//                 if(j->val)
//                 cout << j->val << " ";
//                 j = nodes.erase(j);
//                 break;
//             }
//         }
//         for (; k != nodes.end(); k++) {
//             if (k->parent == prt) {
//                 if(k->val)
//                 cout << k->val << " ";
//                 k = nodes.erase(k);
//                 break;
//             }
//         }
        
        
//         if (j != nodes.end()) {
//             i = j;
//         } else if(k != nodes.end()) {
//             i = k;            
//         }else{
//             i = nodes.begin();
//         }
//     }
//     return 0;
// }