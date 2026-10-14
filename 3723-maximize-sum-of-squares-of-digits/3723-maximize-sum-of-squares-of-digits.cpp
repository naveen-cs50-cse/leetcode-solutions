#include <string>
#include <algorithm>

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if ((long long)num * 9 < sum || sum < 1) {
            return "";
        }
        
        std::string result = "";
        
        // Add as many '9's as possible
        int nines = sum / 9;
        int remainder = sum % 9;
        
        for (int i = 0; i < nines; ++i) {
            result += '9';
        }
        
        // Add the remainder digit if it exists
        if (remainder > 0) {
            result += std::to_string(remainder);
        }
        
        // Fill the rest of the positions with '0's
        while (result.length() < num) {
            result += '0';
        }
        
        return result;
    }
};