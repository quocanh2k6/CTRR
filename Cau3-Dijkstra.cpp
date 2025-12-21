#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
#include <iomanip> // Thư viện để căn lề (setw)
using namespace std;
const int maxn = 11000011, INF = 1e9; // Số vô cùng
int n, m, s, t, pre[maxn];
vector<pair<int, int>> adj[maxn]; // Lưu {đỉnh kề, trọng số}
void Dijkstra(int s, int t)
{
    vector<int> d(n + 1, INF);          // Mảng khoảng cách
    vector<bool> visited(n + 1, false); // Mảng đánh dấu đã thăm
    d[s] = 0;
    pre[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while (!Q.empty())
    {
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] = u;
            }
        }
    }
    cout << " Khoang cach ngan nhat la: " << d[t] << endl;
    vector<int> path;
    while (1)
    {
        path.push_back(t);
        if (t == s)
            break;
        t = pre[t];
    }
    reverse(begin(path), end(path));
    cout << " Duong di ngan nhat: ";
    for (int x : path)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << " Khoang cach ngan nhat tu dinh s toi cac dinh khac: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    cout << " Nhap dinh dau s: " << ' ';
    cin >> s;
    cout << " Nhap dinh cuoi t: " << ' ';
    cin >> t;
    Dijkstra(s, t);
}