#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // Stores indices of heights in non-decreasing order
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            // Use 0 as a dummy height at index n to pop all remaining elements from stack
            int current_height = (i == n) ? 0 : heights[i];

            while (!st.empty() && current_height < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                // Width is the distance between current index i and new stack top index - 1
                int w = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, h * w);
            }
            st.push(i);
        }

        return max_area;
    }
};