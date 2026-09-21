#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> result(k, 0);
        std::vector<long long> dp(k, 0);

        for (int num : nums) {
            std::vector<long long> next_dp(k, 0);
            int mod_val = num % k;

            // Extend existing subarrays
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * mod_val) % k;
                    next_dp[new_rem] += dp[r];
                }
            }

            // Start a new subarray consisting of just `num`
            next_dp[mod_val]++;

            // Accumulate counts into the final result
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return result;
    }
};