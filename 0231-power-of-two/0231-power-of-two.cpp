class Solution {
public:
    bool isPowerOfTwo(int n) {

        int x=0;
        while(n>0)
        {
            if(n%2==1)
                    x++;
            
            n=n/2;
        }
        

        if(x==1)
        {
            return true;
        }

        return false;
    }
};