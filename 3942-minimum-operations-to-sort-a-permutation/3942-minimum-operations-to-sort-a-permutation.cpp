#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Check if nums is a cyclic shift of increasing order [0, 1, ..., n-1]
        // or a cyclic shift of decreasing order [n-1, ..., 1, 0].
        
        auto is_cyclic = [&](const std::vector<int>& target) {
            int shift = -1;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == target[0]) {
                    shift = i;
                    break;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (nums[(shift + i) % n] != target[i]) {
                    return -1;
                }
            }
            return shift;
        };

        std::vector<int> inc(n);
        std::iota(inc.begin(), inc.end(), 0);
        std::vector<int> dec(n);
        for (int i = 0; i < n; ++i) dec[i] = n - 1 - i;

        int inc_shift = is_cyclic(inc);
        int dec_shift = is_cyclic(dec);

        if (inc_shift == -1 && dec_shift == -1) {
            return -1;
        }

        int min_ops = 1e9;

        // Case 1: Increasing cyclic rotations
        if (inc_shift != -1) {
            // Option A: Just rotate left `inc_shift` times
            min_ops = std::min(min_ops, inc_shift);
            // Option B: Reverse, then rotate, then reverse
            // Reverse costs 1, rotation costs (n - inc_shift) % n, reverse costs 1 -> Total = 2 + (n - inc_shift) % n
            min_ops = std::min(min_ops, 2 + (n - inc_shift) % n);
        }

        // Case 2: Decreasing cyclic rotations
        if (dec_shift != -1) {
            // Option A: Reverse first (1 op), then rotate left `dec_shift` times (dec_shift ops) -> Total = 1 + dec_shift
            min_ops = std::min(min_ops, 1 + dec_shift);
            // Option B: Rotate left first, then reverse -> Total = (n - dec_shift) % n + 1
            min_ops = std::min(min_ops, 1 + (n - dec_shift) % n);
        }

        return min_ops;
    }
};