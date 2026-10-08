class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        long long xr = 0;

        // XOR all numbers
        for (int num : nums) {
            xr ^= num;
        }

        // Get rightmost set bit
        long long bit = xr & (-xr);

        long long a = 0;
        long long b = 0;

        // Divide into two groups
        for (int num : nums) {

            if (num & bit)
                a ^= num;
            else
                b ^= num;
        }

        return {(int)a, (int)b};
    }
};