#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int currentWidth = right - left;
            int currentHeight = std::min(height[left], height[right]);
            int currentArea = currentWidth * currentHeight;
            
            maxWater = std::max(maxWater, currentArea);

            // Move the pointer pointing to the shorter line to try and find a taller boundary
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};