class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        int left = 1, right = x / 2;
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Using division mid <= x / mid to prevent integer overflow
            if (mid <= x / mid) {
                ans = mid;     // mid is a valid potential answer, try searching higher
                left = mid + 1;
            } else {
                right = mid - 1; // mid * mid > x, search lower half
            }
        }
        
        return ans;
    }
};