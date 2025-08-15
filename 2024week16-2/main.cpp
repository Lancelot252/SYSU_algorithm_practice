#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX_N = 100;
const int dx[] = {-1, 0, 1, 0}; // 北东南西方向的行偏移
const int dy[] = {0, 1, 0, -1}; // 北东南西方向的列偏移

struct Point {
    int x, y, cost;
    Point(int _x, int _y, int _c) : x(_x), y(_y), cost(_c) {}
    bool operator>(const Point& other) const {
        return cost > other.cost;
    }
};

// 使用Dijkstra算法找到从起点到终点的最小燃料路径
int findMinFuel(vector<vector<int>>& grid, int startX, int startY, int endX, int endY) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX)); // 初始化距离数组，所有值为无穷大
    priority_queue<Point, vector<Point>, greater<Point>> pq; // 优先队列，用于存储待处理的点
    
    dist[startX-1][startY-1] = grid[startX-1][startY-1]; // 起点的燃料消耗为其自身的燃料值
    pq.push(Point(startX-1, startY-1, grid[startX-1][startY-1])); // 将起点加入优先队列
    
    while (!pq.empty()) {
        Point curr = pq.top(); // 取出当前燃料消耗最小的点
        pq.pop();
        
        if (curr.x == endX-1 && curr.y == endY-1) { // 如果到达终点，返回当前的燃料消耗
            return dist[curr.x][curr.y];
        }
        
        for (int i = 0; i < 4; i++) { // 遍历四个方向
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) { // 检查新位置是否在网格范围内
                int newCost = dist[curr.x][curr.y] + grid[nx][ny]; // 计算新位置的燃料消耗
                if (newCost < dist[nx][ny]) { // 如果新位置的燃料消耗更小，更新距离数组
                    dist[nx][ny] = newCost;
                    pq.push(Point(nx, ny, newCost)); // 将新位置加入优先队列
                }
            }
        }
    }
    return -1; // 如果无法到达终点，返回-1
}

int main() {
    int T;
    cin >> T; // 读取测试用例数量
    
    while (T--) {
        int rows, cols;
        cin >> rows >> cols; // 读取网格的行数和列数
        
        vector<vector<int>> grid(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> grid[i][j]; // 读取网格数据
            }
        }
        
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY; // 读取起点和终点坐标
        
        cout << findMinFuel(grid, startX, startY, endX, endY) << endl; // 输出最小燃料消耗
    }
    
    return 0; // 程序结束
}
