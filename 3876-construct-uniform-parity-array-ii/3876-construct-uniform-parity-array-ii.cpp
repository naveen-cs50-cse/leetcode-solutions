#include <vector>
#include <algorithm>

class Solution {
public:
    bool uniformArray(std::vector<int>& nums1) {
        bool hasEven = false;
        bool hasOdd = false;
        int minVal = nums1[0];

        for (int x : nums1) {
            if (x % 2 == 0) {
                hasEven = true;
            } else {
                hasOdd = true;
            }
            if (x < minVal) {
                minVal = x;
            }
        }

        // If all elements already have the same parity, it's always true
        if (!hasEven || !hasOdd) {
            return true;
        }

        // With a mix of odd and even, we need the minimum element to be odd
        return (minVal % 2 != 0);
    }
};