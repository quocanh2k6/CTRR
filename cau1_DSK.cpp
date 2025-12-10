#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip> // Thư viện để căn lề (setw)

using namespace std;

int n, m;
int matrix[100][100]; // Ma trận kề

int main() {
    // 1. Đọc file
    ifstream in("mau.txt");
    if (!in) {
        cout << "Loi: Khong tim thay file mau.txt" << endl;
        return 1;
    }

    in >> n >> m;

    // Khởi tạo ma trận toàn số 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) matrix[i][j] = 0;
    }

    // Đọc các cạnh và điền vào ma trận
    for (int i = 0; i < m; i++) {
        int u, v, w;
        in >> u >> v >> w;
        // Đồ thị vô hướng: a[u][v] = a[v][u] = trọng số
        matrix[u][v] = w;
        matrix[v][u] = w;
    }
    in.close();

    // 2. Xuất ma trận kề
    cout << "--- MA TRAN KE ---\n\n";
    
    // In hàng tiêu đề số đỉnh
    cout << "      ";
    for(int i = 1; i <= n; i++) cout << setw(4) << i;
    cout << endl << endl;

    // In nội dung ma trận
    for (int i = 1; i <= n; i++) {
        cout << setw(4) << i << "  "; // In cột tiêu đề
        for (int j = 1; j <= n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}