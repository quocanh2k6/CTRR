#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <iomanip> // Thư viện để căn lề (setw)
#include <cstring>
using namespace std;
int n, m;
vector<int> adj[100]; // Danh sách kề (chỉ cần lưu đỉnh kề)
bool visited[100];    // Mảng đánh dấu đã thăm
void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // Đồ thị vô hướng
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
}
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " "; // Duyệt các đỉnh kề của v
        for (int w : adj[v])
        {
            if (!visited[w])
            {
                q.push(w);
                visited[w] = true;
            }
        }
    }
}
int main()
{
    inp();
    bfs(1);
}