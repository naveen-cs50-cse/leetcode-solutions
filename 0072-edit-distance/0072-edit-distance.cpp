class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[j] stores the edit distance for word1 prefix and word2[0...j-1]
        vector<int> dp(n + 1, 0);
        
        // Base case: converting empty word1 prefix to word2[0...j] requires j insertions
        for (int j = 0; j <= n; ++j) {
            dp[j] = j;
        }
        
        for (int i = 1; i <= m; ++i) {
            int prev = dp[0]; // Stores dp[i-1][j-1]
            dp[0] = i;        // Base case: converting word1[0...i] to empty word2 requires i deletions
            
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev; // Characters match, no operation needed
                } else {
                    dp[j] = 1 + min({
                        dp[j],     // Deletion: dp[i-1][j]
                        dp[j - 1], // Insertion: dp[i][j-1]
                        prev       // Replacement: dp[i-1][j-1]
                    });
                }
                
                prev = temp;
            }
        }
        
        return dp[n];
    }
};