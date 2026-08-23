class Solution {
public:

    void sub(string digits, vector<string>& arr,
             vector<string>& ans, int index, string current)
    {
        // We have processed all digits
        if(index == digits.length())
        {
            ans.push_back(current);
            return;
        }

        // Get letters corresponding to current digit
        string letters = arr[digits[index] - '0'];

        // Try every letter
        for(char ch : letters)
        {
            current.push_back(ch);

            sub(digits, arr, ans, index + 1, current);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> arr = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;

        sub(digits, arr, ans, 0, "");

        return ans;
    }
};