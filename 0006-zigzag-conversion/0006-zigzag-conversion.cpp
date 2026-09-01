

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge cases: no zigzag needed if only 1 row or string length fits in numRows
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            
            // Change direction when hitting the top or bottom boundaries
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all row strings together
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};