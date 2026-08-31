class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=i+1;j<n;j++)
            {
                temp=nums[i]+nums[j];
                if(temp==target)
                {
                     return {i, j};
                }
            }
        }
        
        return {-1,-1};
    }
};