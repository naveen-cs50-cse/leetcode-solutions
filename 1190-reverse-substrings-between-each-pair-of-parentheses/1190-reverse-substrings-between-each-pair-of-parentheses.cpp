#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        
        for (char c : s) {
            if (c == ')') {
                string temp = "";
                while (!res.empty() && res.back() != '(') {
                    temp += res.back();
                    res.pop_back();
                }
                res.pop_back(); // Remove '('
                res += temp;    // Append reversed segment
            } else {
                res.push_back(c);
            }
        }
        
        return res;
    }
};