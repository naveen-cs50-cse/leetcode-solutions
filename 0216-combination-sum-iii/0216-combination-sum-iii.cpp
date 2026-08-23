class Solution {
public:

    void subs(vector<int> arr,vector<vector<int>> &ans,int n,int target,int index,vector<int>temp)
    {
        if(target==0 && temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }
        if(temp.size()==n)
        {
            return;
        }
        if(index>=9)
        {
            return;
        }

        if((target-arr[index])>=0)
        {
            temp.push_back(arr[index]);
            subs(arr,ans,n,target-arr[index],index+1,temp);
            temp.pop_back();
        }

        subs(arr,ans,n,target,index+1,temp);

    }
    vector<vector<int>> combinationSum3(int k, int n) {

            vector<vector<int>> ans;
            vector<int>temp;

            vector<int> arr={1,2,3,4,5,6,7,8,9};

            subs(arr,ans,k,n,0,temp);

            return ans;
        
    }
};