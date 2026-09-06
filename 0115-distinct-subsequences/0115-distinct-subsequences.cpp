class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // dp[j] stores the number of ways to form t[0...j-1]
        // Using unsigned long long to prevent integer overflow during intermediate additions
        vector<unsigned long long> dp(m + 1, 0);
        
        // Base case: 1 way to form an empty string t
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            // Traverse backwards to avoid overwriting values needed from the previous state
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        
        return dp[m];
    }
};