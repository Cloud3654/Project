#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int boardSize;
int mineCount;

vector<vector<char>> board;
vector<vector<char>> rvboard;
int flagCount = 0;
int revealCount = 0;

void placeMines() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, boardSize - 1);
    int placed = 0;
    while (placed < mineCount) {
        int x = dis(gen);
        int y = dis(gen);
        if (board[y][x] != 'M') {
            board[y][x] = 'M';
            placed++;
        }
    }
}

void printBoard(const vector<vector<char>>& b) {
    cout << "   ";
    for (int i = 0; i < boardSize; i++) printf("%2d", i);
    cout << endl;
    for (int y = 0; y < boardSize; y++) {
        printf("%2d ", y);
        for (int x = 0; x < boardSize; x++) {
            printf("%2c", b[y][x]);
        }
        cout << endl;
    }
    cout << "Flag Count: " << flagCount << endl;
}

void reveal(int x, int y) {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) return;
    if (rvboard[y][x] != '*') return;
    revealCount++;
    int dx[8] = {1,1,1,0,0,-1,-1,-1};
    int dy[8] = {1,0,-1,1,-1,1,0,-1};
    int minecount = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
            if (board[ny][nx] == 'M') minecount++;
        }
    }
    if (minecount == 0) {
        rvboard[y][x] = ' ';
        for (int i = 0; i < 8; i++) reveal(x + dx[i], y + dy[i]);
    }
    else rvboard[y][x] = minecount + '0';
}

bool rv(int x, int y) {
    if (board[y][x] == 'M') return false;
    reveal(x, y);
    return true;
}

void flag(int x, int y) {
    if (rvboard[y][x] != 'F') {
        flagCount++;
        rvboard[y][x] = 'F';
    }
    else {
        flagCount--;
        rvboard[y][x] = '*';
    }
}

int main() {
    cout << "Enter board size (max 50): ";
    cin >> boardSize;
    if (boardSize <= 0 || boardSize > 50) {
        cout << "Invalid size\n";
        return 1;
    }
    cout << "Enter number of mines: ";
    cin >> mineCount;
    if (mineCount <= 0 || mineCount >= boardSize * boardSize) {
        cout << "Invalid number of mines\n";
        return 1;
    }

    board.assign(boardSize, vector<char>(boardSize, '*'));
    rvboard.assign(boardSize, vector<char>(boardSize, '*'));

    placeMines();
    printBoard(rvboard);

    srand(time(0));
    char c; int x, y;
    while (true) {
        cin >> c >> x >> y;
        if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) {
            cout << "Invalid coordinates\n";
            continue;
        }
        if (c == 'c') {
            if (!rv(x, y)) {
                cout << "\nGame Over!\n\n";
                break;
            }
        }
        else if (c == 'f') {
            flag(x, y);
        }
        if (revealCount == boardSize * boardSize - mineCount) {
            cout << "\nYou Win!\n\n" << endl;
            break;
        }
        printBoard(rvboard);
    }
    printBoard(board);

    return 0;
}
