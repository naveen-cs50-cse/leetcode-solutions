class Solution {
private:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If we hit the boundary, this island is NOT closed
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        // If it's water (1), it's safe (doesn't invalidate the island)
        if (grid[r][c] == 1) {
            return true;
        }
        
        // Mark the current land cell as visited by changing it to water (1)
        grid[r][c] = 1;
        
        // Explore all 4 directions
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        
        // The island is closed only if all four directions are valid/safe
        return up && down && left && right;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Flood fill all land (0) connected to the boundaries
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(r, c, grid);
                }
            }
        }
        
        // Step 2: Count remaining closed islands in the interior
        int closedIslandsCount = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    // If dfs returns true, it's a valid closed island
                    if (dfs(r, c, grid)) {
                        closedIslandsCount++;
                    }
                }
            }
        }
        
        return closedIslandsCount;
    }
};