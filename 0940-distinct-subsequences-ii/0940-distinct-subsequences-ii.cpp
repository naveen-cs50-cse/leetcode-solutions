class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        // last[c] stores the number of distinct subsequences ending with character 'c'
        vector<long long> last(26, 0);
        
        for (char c : s) {
            int idx = c - 'a';
            // Total subsequences ending with character 'c' equals 1 (for 'c' itself) 
            // plus the sum of all previously formed distinct subsequences appended with 'c'.
            long long sumAll = 0;
            for (int i = 0; i < 26; ++i) {
                sumAll = (sumAll + last[i]) % MOD;
            }
            
            last[idx] = (sumAll + 1) % MOD;
        }
        
        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + last[i]) % MOD;
        }
        
        return result;
    }
};