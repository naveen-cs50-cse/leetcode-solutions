class Solution {
public:

    void combination(vector<int>arr,vector<vector<int>> &ans,int target,vector<int>temp,int index)
    {
        if(target==0)
        {
            ans.push_back(temp);
        }

        for(int i=index;i<arr.size();i++)
        {

            if(i>index && arr[i]==arr[i-1])
            {
                continue;
            }

          if((target-arr[i])>=0)
           {
              temp.push_back(arr[i]);
              combination(arr,ans,target-arr[i],temp,i+1);
              temp.pop_back();
            }

        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int>temp;

        sort(candidates.begin(),candidates.end());

        combination(candidates,ans,target,temp,0);

        return ans;
        
    }
};