class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int max_k = -1;
        
        for (int i = 0; i < n; ++i) {
            // Check if the element is not in its correct position
            if (nums[i] != i) {
                if (max_k == -1) {
                    max_k = nums[i];
                } else {
                    max_k &= nums[i];
                }
            }
        }
        
        // If all elements are already in their correct positions
        if (max_k == -1) {
            return 0;
        }
        
        return max_k;
    }
};