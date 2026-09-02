#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0;
        
        int n = haystack.length();
        int m = needle.length();
        
        if (m > n) return -1;

        for (int i = 0; i <= n - m; ++i) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
};