class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            int j = i;
            int lineLength = 0;
            
            // Determine how many words fit in the current line
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }
            
            int numWords = j - i;
            int totalSpaces = maxWidth - lineLength;
            string line = "";
            
            // If it's the last line or the line contains only 1 word -> Left Justify
            if (j == n || numWords == 1) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            } 
            // Fully justify (distribute extra spaces as evenly as possible)
            else {
                int baseSpaces = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToApply = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line += string(spacesToApply, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};