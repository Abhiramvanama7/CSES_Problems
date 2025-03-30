#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directions: up, down, left, right using pair<int, int>
const vector<pair<int, int>> directions = {
    {-1, 0},  // up
    {1, 0},   // down
    {0, -1},  // left
    {0, 1}    // right
};

// BFS to explore one full room starting from (row, col)
void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m) {
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while (!q.empty()) {
        auto [currentRow, currentCol] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int newRow = currentRow + dx;
            int newCol = currentCol + dy;

            // Check bounds and unvisited floor cell
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input grid
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    // Visited matrix
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCount = 0;

    // Traverse the grid
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            if (grid[row][col] == '.' && !visited[row][col]) {
                bfs(row, col, grid, visited, n, m);
                roomCount++;
            }
        }
    }

    cout << roomCount << endl;
    return 0;
}
