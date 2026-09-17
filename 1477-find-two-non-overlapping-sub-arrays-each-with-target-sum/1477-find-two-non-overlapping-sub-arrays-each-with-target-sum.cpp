#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // min_len[i] stores the minimum length of a valid subarray ending at or before index i
        vector<int> min_len(n, INT_MAX);
        
        int current_sum = 0;
        int left = 0;
        int min_total_sum = INT_MAX;
        int best_so_far = INT_MAX; // Minimum length of valid subarray seen up to current index
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            // Shrink window if sum exceeds target
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            
            // Found a valid subarray with sum == target
            if (current_sum == target) {
                int curr_len = right - left + 1;
                
                // If there's a valid subarray that strictly ends before index `left`, combine them
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    min_total_sum = min(min_total_sum, curr_len + min_len[left - 1]);
                }
                
                best_so_far = min(best_so_far, curr_len);
            }
            
            min_len[right] = best_so_far;
        }
        
        return min_total_sum == INT_MAX ? -1 : min_total_sum;
    }
};