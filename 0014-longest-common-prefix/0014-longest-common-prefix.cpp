#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        for (int i = 0; i < strs[0].length(); i++) {
            char currentChar = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                // Check if index exceeds string length or character mismatches
                if (i == strs[j].length() || strs[j][i] != currentChar) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};