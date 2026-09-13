#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to calculate the largest rectangle area in a 1D histogram
    int largestRectangleArea(const vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            int current_height = (i == n) ? 0 : heights[i];

            while (!st.empty() && current_height < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, h * w);
            }
            st.push(i);
        }

        return max_area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int max_rectangle = 0;

        // Process row by row, updating histogram heights
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == '1') {
                    heights[c] += 1;
                } else {
                    heights[c] = 0; // Reset height if there's a 0
                }
            }
            // Find max rectangle area for the current row's histogram
            max_rectangle = max(max_rectangle, largestRectangleArea(heights));
        }

        return max_rectangle;
    }
};