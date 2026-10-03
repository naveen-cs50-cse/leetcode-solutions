#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index to serve as a boundary for valid substrings
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Push current index as a new boundary for future valid substrings
                    st.push(i);
                } else {
                    // Length is current index minus index of last unmatched boundary
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};