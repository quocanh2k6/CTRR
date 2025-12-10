#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int n, m;
vector<int> adj[100]; // Danh sách kề (chỉ cần lưu đỉnh kề)
bool visited[100];    // Mảng đánh dấu đã thăm

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "Ket qua duyet BFS tu dinh " << start << ": ";
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        // Duyệt các đỉnh kề của u
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    // 1. Đọc file
    ifstream in("mau.txt");
    if (!in) {
        cout << "Khong tim thay file mau.txt" << endl;
        return 1;
    }

    in >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        in >> u >> v >> w;
        // Đồ thị vô hướng
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    in.close();

    // 2. Nhập đỉnh bắt đầu và chạy BFS
    int startNode;
    cout << "Nhap dinh bat dau duyet BFS: ";
    cin >> startNode;

    // Reset mảng visited
    for(int i=1; i<=n; i++) visited[i] = false;

    BFS(startNode);

    return 0;
}