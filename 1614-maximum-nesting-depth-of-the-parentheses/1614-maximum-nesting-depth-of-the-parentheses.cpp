class Solution {
public:
    int maxDepth(string s) {

        int streak=0;
        int maxe=INT_MIN;

        for(char c : s)
        {
            if(c=='(')
            {
                streak+=1;

                maxe=max(maxe,streak);
            }
            else if(c==')')
            {
                streak-=1;
            }
        }
        if(maxe==INT_MIN)
                return 0;
        return maxe;
        
    }
};