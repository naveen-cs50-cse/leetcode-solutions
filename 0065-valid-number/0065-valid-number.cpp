#include <string>
#include <cctype>

class Solution {
public:
    bool isNumber(std::string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (std::isdigit(c)) {
                seenDigit = true;
            } else if (c == '+' || c == '-') {
                // Sign is only valid at the start or immediately after 'e' or 'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (c == '.') {
                // Dot is invalid if we already saw a dot or an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                // Exponent is invalid if we already saw one or haven't seen any digit yet
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; // Reset to require at least one digit after 'e'/'E'
            } else {
                // Invalid character
                return false;
            }
        }

        return seenDigit;
    }
};