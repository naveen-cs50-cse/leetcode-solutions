class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Store knowledge key-value pairs in an unordered_map for O(1) lookup
        unordered_map<string, string> mp;
        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string result = "";
        string key = "";
        bool in_bracket = false;

        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
            } else if (c == ')') {
                in_bracket = false;
                // Check if key exists in knowledge map
                if (mp.count(key)) {
                    result += mp[key];
                } else {
                    result += '?';
                }
                key = ""; // Reset key buffer
            } else if (in_bracket) {
                key += c;
            } else {
                result += c;
            }
        }

        return result;
    }
};