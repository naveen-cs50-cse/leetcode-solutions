class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // Track occupied columns, main diagonals (row - col), and anti-diagonals (row + col)
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false); // row - col + n
        vector<bool> diag2(2 * n, false); // row + col

        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }

private:
    void backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int& count) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            // Place queen
            cols[col] = diag1[d1] = diag2[d2] = true;

            backtrack(row + 1, n, cols, diag1, diag2, count);

            // Remove queen (backtrack)
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};