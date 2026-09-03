#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '1'; // Map '1'-'9' to 0-8
                int mask = 1 << val;
                int boxIndex = (r / 3) * 3 + (c / 3);

                // Check if digit already exists in row, col, or 3x3 box
                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIndex] & mask)) {
                    return false;
                }

                // Mark digit as seen
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIndex] |= mask;
            }
        }

        return true;
    }
};