#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> sorted_intervals(n);
        
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        // Sort intervals by their right boundary (end time)
        sort(sorted_intervals.begin(), sorted_intervals.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });

        // Store sorted end points for binary searching previous non-overlapping interval
        vector<int> end_times(n);
        for (int i = 0; i < n; ++i) {
            end_times[i] = sorted_intervals[i].r;
        }

        // dp[k][i] stores {max_score, vector_of_indices} for picking up to k intervals from prefix [0...i]
        // k ranges from 0 to 4
        vector<vector<pair<long long, vector<int>>>> dp(5, vector<pair<long long, vector<int>>>(n + 1, {0, {}}));

        for (int i = 1; i <= n; ++i) {
            int current_l = sorted_intervals[i - 1].l;
            int current_weight = sorted_intervals[i - 1].weight;
            int current_id = sorted_intervals[i - 1].id;

            // Find largest index j such that sorted_intervals[j].r < current_l
            // std::lower_bound finds first index with end_time >= current_l
            int j = lower_bound(end_times.begin(), end_times.end(), current_l) - end_times.begin();

            for (int k = 1; k <= 4; ++k) {
                // Option 1: Do not include the current interval
                auto best = dp[k][i - 1];

                // Option 2: Include the current interval (combining with best state from prefix j)
                long long take_weight = dp[k - 1][j].first + current_weight;
                vector<int> take_indices = dp[k - 1][j].second;
                take_indices.push_back(current_id);
                sort(take_indices.begin(), take_indices.end());

                // Compare weight, then lexicographical order of indices
                if (take_weight > best.first) {
                    best = {take_weight, take_indices};
                } else if (take_weight == best.first && !take_indices.empty()) {
                    if (best.second.empty() || take_indices < best.second) {
                        best = {take_weight, take_indices};
                    }
                }

                dp[k][i] = best;
            }
        }

        return dp[4][n].second;
    }
};