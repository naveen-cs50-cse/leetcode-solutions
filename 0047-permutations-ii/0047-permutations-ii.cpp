class Solution {
private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip if element is already used in the current permutation branch
            if (used[i]) continue;

            // Skip duplicates: if the current element is equal to the previous one 
            // and the previous element was not used in this path, skip to prevent duplicates.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current, result);

            current.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        // Sorting groups identical numbers together to simplify duplicate checks
        sort(nums.begin(), nums.end());
        backtrack(nums, used, current, result);

        return result;
    }
};