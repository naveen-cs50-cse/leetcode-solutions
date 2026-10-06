#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;   // Count of '(' needed to balance unmatched ')'
        int close_needed = 0;  // Count of ')' needed to balance unmatched '('

        for (char c : s) {
            if (c == '(') {
                close_needed++;
            } else {
                if (close_needed > 0) {
                    close_needed--;  // Found a matching ')' for an open '('
                } else {
                    open_needed++;   // Found a ')' without a preceding '('
                }
            }
        }

        return open_needed + close_needed;
    }
};