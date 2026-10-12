class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(31, 0);
        for (int num : nums) {
            for (int i = 0; i <= 30; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        long long totalSum = 0;
        long long MOD = 1e9 + 7;
        
        for (int step = 0; step < k; ++step) {
            long long currentNum = 0;
            for (int i = 30; i >= 0; --i) {
                if (bitCount[i] > 0) {
                    currentNum |= (1LL << i);
                    bitCount[i]--;
                }
            }
            totalSum = (totalSum + (currentNum * currentNum) % MOD) % MOD;
        }
        
        return totalSum;
    }
};