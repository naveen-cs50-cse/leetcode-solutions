class Solution {
public:
    int minBitFlips(int start, int goal) {
        int need=0;
        while(start || goal)
        {
            int i=start%2;
            int j=goal%2;
            start/=2;
            goal/=2;

            if(i!=j)
            {
                need=need+1;
            }

        }

        return need;
        
    }
};