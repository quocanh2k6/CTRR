#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <iomanip>

using namespace std;

const int INF = 1e9; // Số vô cùng
int n, m;
vector<pair<int, int>> adj[100]; // Lưu {đỉnh kề, trọng số}

void Dijkstra(int start) {
    // Priority queue để lấy đỉnh có khoảng cách nhỏ nhất ra trước
    // Cấu trúc: pair<khoảng_cách, đỉnh>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> d(n + 1, INF);      // Mảng khoảng cách
    vector<int> parent(n + 1, -1);  // Mảng lưu vết đường đi

    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > d[u]) continue;

        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            // Nếu tìm thấy đường ngắn hơn
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                parent[v] = u; // Lưu vết: cha của v là u
                pq.push({d[v], v});
            }
        }
    }

    // Xuất kết quả
    cout << "\n--- KET QUA DIJKSTRA TU DINH " << start << " ---\n";
    cout << "Dich | Do dai | Lo trinh\n";
    cout << "------------------------\n";
    for (int i = 1; i <= n; i++) {
        if (i == start) continue; // Bỏ qua đỉnh xuất phát
        
        cout << "  " << i << "  | " << setw(6) << d[i] << " | ";
        
        if (d[i] == INF) {
            cout << "Khong co duong đi";
        } else {
            // Truy vết ngược từ đích về nguồn
            vector<int> path;
            for (int v = i; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            // In xuôi
            for (int j = path.size() - 1; j >= 0; j--) {
                cout << path[j] << (j > 0 ? " -> " : "");
            }
        }
        cout << endl;
    }
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
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    in.close();

    // 2. Chạy Dijkstra từ đỉnh 1 (theo yêu cầu đề bài)
    Dijkstra(1);

    return 0;
}