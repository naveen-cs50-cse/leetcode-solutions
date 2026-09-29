#include <vector>

using namespace std;

class Solution {
    bool visited[100][100][105];
    int m, n;

public:
    bool dfs(vector<vector<char>>& grid, int r, int c, int open) {
        // Increment for '(' and decrement for ')'
        open += (grid[r][c] == '(' ? 1 : -1);

        // If open count becomes negative, the current path is invalid
        if (open < 0) return false;

        // If open count exceeds maximum possible remaining path length, prune
        if (open > (m - r + n - c - 1)) return false;

        // Reached destination: check if all brackets are balanced
        if (r == m - 1 && c == n - 1) {
            return open == 0;
        }

        // If already visited this state, return false (since it didn't succeed previously)
        if (visited[r][c][open]) return false;
        visited[r][c][open] = true;

        // Move right
        if (c + 1 < n && dfs(grid, r, c + 1, open)) return true;

        // Move down
        if (r + 1 < m && dfs(grid, r + 1, c, open)) return true;

        return false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length is m + n - 1. If it's odd, a valid sequence is impossible.
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        return dfs(grid, 0, 0, 0);
    }
};