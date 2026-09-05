class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // If current index is unreachable, return false
            if (i > maxReach) {
                return false;
            }
            // Update the maximum index reachable so far
            maxReach = max(maxReach, i + nums[i]);
            
            // Early return if last index is reachable
            if (maxReach >= n - 1) {
                return true;
            }
        }

        return true;
    }
};