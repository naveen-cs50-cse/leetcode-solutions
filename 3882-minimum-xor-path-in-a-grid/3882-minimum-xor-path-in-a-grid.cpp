#include <vector>
#include <bitset>
#include <algorithm>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[j][x] will store whether an XOR sum of 'x' is achievable at column j
        // We can optimize space to 1D for the columns since we only need the previous row.
        std::vector<std::bitset<1024>> dp(n);
        
        // Base case: starting cell (0, 0)
        dp[0].set(grid[0][0]);
        
        // Initialize first row (can only come from the left)
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j - 1];
            // Shift all set bits by applying XOR with grid[0][j]
            dp[j] = (dp[j] << grid[0][j]) | (dp[j] >> (1024 - grid[0][j])); // Wait, bitset shift doesn't do circular XOR. 
            // Instead, let's build it safely:
        }
        
        // Let's rewrite using a cleaner loop-based approach for row/col transitions:
        // dp[i][j] means a bitset of possible XOR values at cell (i, j).
        std::vector<std::vector<std::bitset<1024>>> memo(m, std::vector<std::bitset<1024>>(n));
        
        memo[0][0].set(grid[0][0]);
        
        // Fill the first row
        for (int j = 1; j < n; ++j) {
            for (int x = 0; x < 1024; ++x) {
                if (memo[0][j - 1].test(x)) {
                    memo[0][j].set(x ^ grid[0][j]);
                }
            }
        }
        
        // Fill the first column
        for (int i = 1; i < m; ++i) {
            for (int x = 0; x < 1024; ++x) {
                if (memo[i - 1][0].test(x)) {
                    memo[i][0].set(x ^ grid[i][0]);
                }
            }
        }
        
        // Fill the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                for (int x = 0; x < 1024; ++x) {
                    if (memo[i - 1][j].test(x) || memo[i][j - 1].test(x)) {
                        memo[i][j].set(x ^ grid[i][j]);
                    }
                }
            }
        }
        
        // Find the minimum XOR value present in the bottom-right cell
        for (int x = 0; x < 1024; ++x) {
            if (memo[m - 1][n - 1].test(x)) {
                return x;
            }
        }
        
        return 0;
    }
};