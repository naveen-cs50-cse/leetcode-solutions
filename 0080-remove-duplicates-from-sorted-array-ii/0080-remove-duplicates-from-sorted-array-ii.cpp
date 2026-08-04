class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=2;
        int n=nums.size();
        if(n<=2){return n;}

        for(int i=2;i<n;i++)
        {
            if(nums[i]!=nums[index-2])
            {
                nums[index]=nums[i];
                index+=1;
            }

        }
        return index;
        
        
    }
};