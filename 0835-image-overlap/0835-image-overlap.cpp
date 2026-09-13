#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Collect coordinates of 1s in both images
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        // Map to count frequencies of shift vectors (row_diff, col_diff)
        // Encode (dr, dc) into a single integer key: (dr + 30) * 100 + (dc + 30)
        unordered_map<int, int> count;
        int max_overlap = 0;

        for (const auto& p1 : ones1) {
            for (const auto& p2 : ones2) {
                int dr = p1.first - p2.first;
                int dc = p1.second - p2.second;
                int key = (dr + 30) * 100 + (dc + 30);
                count[key]++;
                max_overlap = max(max_overlap, count[key]);
            }
        }

        return max_overlap;
    }
};