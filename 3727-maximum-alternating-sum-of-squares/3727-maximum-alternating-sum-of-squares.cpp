class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            squares[i] = val * val;
        }
        
        sort(squares.begin(), squares.end());
        
        long long score = 0;
        int mid = n / 2;
        
        // Subtract the smaller half
        for (int i = 0; i < mid; ++i) {
            score -= squares[i];
        }
        
        // Add the larger half
        for (int i = mid; i < n; ++i) {
            score += squares[i];
        }
        
        return score;
    }
};