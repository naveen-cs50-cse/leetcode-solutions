class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;
        
        // Split the string by '/'
        while (getline(ss, token, '/')) {
            // Ignore empty tokens (from repeated slashes) and current directory '.'
            if (token == "" || token == ".") {
                continue;
            }
            // Go up one level for '..', if possible
            if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } 
            // Valid directory or file name
            else {
                st.push_back(token);
            }
        }
        
        // Construct the canonical path
        string result = "";
        for (const string& dir : st) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};