class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open_count = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                open_count++;
            } else { // s[i] == ')'
                // Check if the next character is also ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // Skip the second ')'
                } else {
                    // Single ')' found, insert one ')' to make it '))'
                    insertions++;
                }
                
                // Now we are processing a complete '))'
                if (open_count > 0) {
                    open_count--; // Matches with an existing '('
                } else {
                    insertions++; // No '(' available, insert one '('
                }
            }
        }
        
        // Each unmatched '(' needs two ')'
        insertions += open_count * 2;
        
        return insertions;
    }
};