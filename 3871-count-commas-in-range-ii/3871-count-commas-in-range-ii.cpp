class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long threshold = 1000; // 10^3, 10^6, 10^9, 10^12, 10^15
        
        while (n >= threshold) {
            ans += (n - threshold + 1);
            // Prevent overflow when threshold * 1000 exceeds LLONG_MAX
            if (threshold > LLONG_MAX / 1000) break;
            threshold *= 1000;
        }
        
        return ans;
    }
};