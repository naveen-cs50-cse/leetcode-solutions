#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // Check if already sorted
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        if (s == sorted_s) return 0;
        
        // Length 2 that cannot be sorted in 1 op (i.e. strictly decreasing)
        if (n == 2) return -1;
        
        char min_char = sorted_s[0];
        char max_char = sorted_s[n - 1];
        
        // Check 1 operation conditions
        // Min char at the beginning (not whole string) or max char at the end (not whole string)
        bool min_at_start = (s[0] == min_char);
        bool max_at_end = (s[n - 1] == max_char);
        
        if (min_at_start || max_at_end) {
            return 1;
        }
        
        // Check if any min_char exists in any proper prefix or max_char in any proper suffix
        bool has_min_prefix = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == min_char) {
                has_min_prefix = true;
                break;
            }
        }
        
        bool has_max_suffix = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == max_char) {
                has_max_suffix = true;
                break;
            }
        }
        
        if (!has_min_prefix && !has_max_suffix) {
            return 3;
        }
        
        return 2;
    }
};