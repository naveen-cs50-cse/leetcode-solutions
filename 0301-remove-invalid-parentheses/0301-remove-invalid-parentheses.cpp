#include <vector>
#include <string>
#include <unordered_set>

class Solution {
private:
    void dfs(int index, int leftCount, int rightCount, int pair, std::string& path, const std::string& s, std::unordered_set<std::string>& result) {
        if (index == s.length()) {
            if (leftCount == 0 && rightCount == 0 && pair == 0) {
                result.insert(path);
            }
            return;
        }

        char c = s[index];

        // Option 1: Remove current character if it's an invalid parenthesis
        if (c == '(' && leftCount > 0) {
            dfs(index + 1, leftCount - 1, rightCount, pair, path, s, result);
        } else if (c == ')' && rightCount > 0) {
            dfs(index + 1, leftCount, rightCount - 1, pair, path, s, result);
        }

        // Option 2: Keep current character
        path.push_back(c);
        if (c != '(' && c != ')') {
            dfs(index + 1, leftCount, rightCount, pair, path, s, result);
        } else if (c == '(') {
            dfs(index + 1, leftCount, rightCount, pair + 1, path, s, result);
        } else if (c == ')' && pair > 0) {
            dfs(index + 1, leftCount, rightCount, pair - 1, path, s, result);
        }
        path.pop_back(); // Backtrack
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        int leftCount = 0, rightCount = 0;

        // Calculate minimum misplaced parentheses
        for (char c : s) {
            if (c == '(') {
                leftCount++;
            } else if (c == ')') {
                if (leftCount > 0) {
                    leftCount--;
                } else {
                    rightCount++;
                }
            }
        }

        std::unordered_set<std::string> result;
        std::string path = "";
        dfs(0, leftCount, rightCount, 0, path, s, result);

        return std::vector<std::string>(result.begin(), result.end());
    }
};