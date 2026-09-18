#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);
        
        // Step 1: Track the first and last occurrences of each character
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        
        vector<pair<int, int>> intervals; // Stores {right_boundary, left_boundary}
        
        // Step 2: Build minimum valid intervals for each character
        for (int c = 0; c < 26; ++c) {
            if (last[c] == -1) continue;
            
            int l = first[c];
            int r = last[c];
            bool valid = true;
            
            for (int i = l; i <= r; ++i) {
                int charIdx = s[i] - 'a';
                if (first[charIdx] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[charIdx]);
            }
            
            if (valid) {
                intervals.push_back({r, l});
            }
        }
        
        // Step 3: Sort intervals by right endpoint
        sort(intervals.begin(), intervals.end());
        
        vector<string> result;
        int prev_r = -1;
        
        // Step 4: Greedily choose non-overlapping intervals
        for (const auto& [r, l] : intervals) {
            if (l > prev_r) {
                result.push_back(s.substr(l, r - l + 1));
                prev_r = r;
            }
        }
        
        return result;
    }
};