class Solution {
    typedef long long ll;

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        ll totalSum = 0;
        unordered_map<int, int> fullMap;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                totalSum += grid[i][j];
                fullMap[grid[i][j]]++;
            }
        }

        // --- 1. Horizontal Cuts ---
        ll topSum = 0;
        unordered_map<int, int> topMap;
        unordered_map<int, int> botMap = fullMap;

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                topSum += val;
                topMap[val]++;
                if (--botMap[val] == 0) botMap.erase(val);
            }
            ll botSum = totalSum - topSum;
            // Section 1: rows [0..i], Section 2: rows [i+1..m-1]
            if (check(topSum, botSum, topMap, botMap, i + 1, n, m - 1 - i, n, 
                      grid[0][0], grid[i][n-1], grid[i+1][0], grid[m-1][n-1])) return true;
        }

        // --- 2. Vertical Cuts ---
        ll leftSum = 0;
        unordered_map<int, int> leftMap;
        unordered_map<int, int> rightMap = fullMap;

        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                int val = grid[i][j];
                leftSum += val;
                leftMap[val]++;
                if (--rightMap[val] == 0) rightMap.erase(val);
            }
            ll rightSum = totalSum - leftSum;
            // Section 1: cols [0..j], Section 2: cols [j+1..n-1]
            if (check(leftSum, rightSum, leftMap, rightMap, m, j + 1, m, n - 1 - j, 
                      grid[0][0], grid[m-1][j], grid[0][j+1], grid[m-1][n-1])) return true;
        }

        return false;
    }

private:
    bool check(ll s1, ll s2, unordered_map<int, int>& m1, unordered_map<int, int>& m2, 
               int r1, int c1, int r2, int c2, int end1a, int end1b, int end2a, int end2b) {
        if (s1 == s2) return true;

        // Try discounting from Section 1 (s1 > s2)
        ll d1 = s1 - s2;
        if (d1 > 0 && d1 <= 100000) {
            if (r1 > 1 && c1 > 1) { if (m1.count((int)d1)) return true; }
            else if (end1a == d1 || end1b == d1) return true;
        }

        // Try discounting from Section 2 (s2 > s1)
        ll d2 = s2 - s1;
        if (d2 > 0 && d2 <= 100000) {
            if (r2 > 1 && c2 > 1) { if (m2.count((int)d2)) return true; }
            else if (end2a == d2 || end2b == d2) return true;
        }

        return false;
    }
};