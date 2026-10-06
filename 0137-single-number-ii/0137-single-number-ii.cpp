class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        
        for (int num : nums) {
            // 'ones' holds the bits that have appeared 1 time (modulo 3)
            // 'twos' holds the bits that have appeared 2 times (modulo 3)
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        
        return ones;
    }
};