class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int so=n*n;
        int se=n*(n+1);
        int s=gcd(so,se);
        return s;
        
    }
};