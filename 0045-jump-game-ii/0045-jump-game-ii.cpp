class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        // We don't need to process the last element because once we reach
        // or surpass it, we are done.
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            // If we've reached the end of the current jump reach
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }

        return jumps;
    }
};