class Solution {
public:

    void combination(vector<vector<int>>& ans,vector<int>& arr, int target,int index,vector<int> temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }

        if((arr.size()==index))
        {
                return;
        }
       
        if((target-arr[index])>=0)
        {
            temp.push_back(arr[index]);
            combination(ans,arr,target-arr[index],index,temp);
            temp.pop_back();
        }
        
        combination(ans,arr,target,index+1,temp);
        
      
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;
        combination(ans,candidates,target,0,temp);

        return ans;
    }
};