#include <iostream>
#include <vector>
#include <set>
using namespace std;

class NQueensSolver {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<int> queens(n, -1); // queens[row] = col
        set<int> columns, diag1, diag2; // for conflict tracking
        backtrack(0, n, queens, columns, diag1, diag2, solutions);
        return solutions;
    }

private:
    void backtrack(int row, int n, vector<int>& queens,
                   set<int>& columns, set<int>& diag1, set<int>& diag2,
                   vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(buildBoard(queens, n));
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (columns.count(col) || diag1.count(row - col) || diag2.count(row + col))
                continue;

            queens[row] = col;
            columns.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            backtrack(row + 1, n, queens, columns, diag1, diag2, solutions);

            // backtrack
            columns.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
            queens[row] = -1;
        }
    }

    vector<string> buildBoard(const vector<int>& queens, int n) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            board[i][queens[i]] = 'Q';
        }
        return board;
    }
};

int main() {
    int n = 8;
    NQueensSolver solver;
    vector<vector<string>> solutions = solver.solveNQueens(n);

    cout << "Total solutions for " << n << "-Queens: " << solutions.size() << "\n";
    for (const auto& board : solutions) {
        for (const string& row : board)
            cout << row << "\n";
        cout << "-----\n";
    }
    return 0;
}
