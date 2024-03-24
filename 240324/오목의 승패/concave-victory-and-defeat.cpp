#include <iostream>
#include <vector>
using namespace std;

const int N = 19;
vector<vector<int>> board(N, vector<int>(N));
vector<vector<vector<int>>> vis(N, vector<vector<int>>(N, vector<int>(4, 0)));

int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, 1, 0, -1};

bool inRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool checkFive(int x, int y, int player, int direction) {
    if (vis[x][y][direction]) return false;
    vis[x][y][direction] = 1;

    int count = 1;
    int nx = x + dx[direction];
    int ny = y + dy[direction];
    
    while (inRange(nx, ny) && board[nx][ny] == player) {
        vis[nx][ny][direction] = 1;
        count++;
        nx += dx[direction];
        ny += dy[direction];
    }

    if (count == 5) {
        int prevX = x - dx[direction];
        int prevY = y - dy[direction];
        int nextX = nx;
        int nextY = ny;
        if (!inRange(prevX, prevY) || board[prevX][prevY] != player) {
            if (!inRange(nextX, nextY) || board[nextX][nextY] != player) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) {
                for (int direction = 0; direction < 4; direction++) {
                    if (checkFive(i, j, board[i][j], direction)) {
                        cout << board[i][j] << endl;
                        cout << i + 1 << " " << j + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << 0 << endl;
    return 0;
}