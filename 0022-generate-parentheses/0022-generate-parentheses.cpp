class Solution {
public:

    void generate(string curr,vector<string> &ans,int n,int left,int right,int size)
    {

        if(size==n*2)
        {
            ans.push_back(curr);
            return;
        }

        if(left<n)
        {
            generate(curr+'(',ans,n,left+1,right,size+1);
        }
        if(right<left)
        {
        generate(curr+')',ans,n,left,right+1,size+1);

        }

    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        
        generate("",ans,n,0,0,0);

        return ans;
    }
};