#include <vector>

using namespace std;

class Solution {
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    int boxIndex = (r / 3) * 3 + (c / 3);

                    for (int d = 1; d <= 9; ++d) {
                        int mask = 1 << (d - 1);

                        // Check if digit 'd' can be placed safely
                        if (!(rows[r] & mask) && !(cols[c] & mask) && !(boxes[boxIndex] & mask)) {
                            // Place digit
                            board[r][c] = '0' + d;
                            rows[r] |= mask;
                            cols[c] |= mask;
                            boxes[boxIndex] |= mask;

                            // Recurse
                            if (solve(board)) return true;

                            // Backtrack
                            board[r][c] = '.';
                            rows[r] &= ~mask;
                            cols[c] &= ~mask;
                            boxes[boxIndex] &= ~mask;
                        }
                    }
                    return false; // No valid digit found for this cell
                }
            }
        }
        return true; // All cells filled
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // Initialize state bitmasks with existing numbers
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int val = board[r][c] - '1';
                    int mask = 1 << val;
                    int boxIndex = (r / 3) * 3 + (c / 3);

                    rows[r] |= mask;
                    cols[c] |= mask;
                    boxes[boxIndex] |= mask;
                }
            }
        }

        solve(board);
    }
};