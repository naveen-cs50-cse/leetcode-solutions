class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // Base case: if the current string length reaches 2 * n, we have a valid combination
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        // If we can still add an open parenthesis, add it and recurse
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }

        // If we can add a close parenthesis (close count must be less than open count), recurse
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};