class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // Minimum possible count of open '('
        int high = 0; // Maximum possible count of open '('

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else if (c == '*') {
                low--;  // '*' treated as ')'
                high++; // '*' treated as '('
            }

            // More ')' than available '(' and '*'
            if (high < 0) return false;

            // Open bracket count cannot drop below 0
            if (low < 0) low = 0;
        }

        return low == 0;
    }
};