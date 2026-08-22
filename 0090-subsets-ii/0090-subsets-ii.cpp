class Solution {
public:
    void subs(vector<vector<int>>& ans, vector<int>& nums, int n, int index, vector<int>& temp) {
        // Base case: if we have considered all elements
        if (index == n) {
            ans.push_back(temp);
            return;
        }

        // Decision 1: Include the current element
        temp.push_back(nums[index]);
        subs(ans, nums, n, index + 1, temp);
        temp.pop_back(); // Backtrack

        // Decision 2: Exclude the current element AND all its duplicates
        while (index + 1 < n && nums[index] == nums[index + 1]) {
            index++;
        }
        subs(ans, nums, n, index + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        
        // 1. Sorting is mandatory to bring duplicates together
        sort(nums.begin(), nums.end());
        
        subs(ans, nums, n, 0, temp);
        return ans;
    }
};
