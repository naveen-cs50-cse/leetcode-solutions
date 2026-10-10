class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalK = (long long)k1 + k2;
        
        // Step 1: Compute absolute differences and count their frequencies
        unordered_map<int, long long> countMap;
        int maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            countMap[diff]++;
            maxDiff = max(maxDiff, diff);
        }
        
        // Step 2: Greedily reduce the largest differences
        for (int d = maxDiff; d > 0 && totalK > 0; --d) {
            if (countMap.find(d) == countMap.end()) continue;
            
            long long freq = countMap[d];
            long long operationsNeeded = min(totalK, freq);
            
            // Reduce 'operationsNeeded' elements from difference 'd' to 'd - 1'
            countMap[d] -= operationsNeeded;
            countMap[d - 1] += operationsNeeded;
            totalK -= operationsNeeded;
        }
        
        // Step 3: Calculate the final minimum sum of squared differences
        long long minSumSq = 0;
        for (auto& pair : countMap) {
            long long diff = pair.first;
            long long freq = pair.second;
            if (diff > 0 && freq > 0) {
                minSumSq += freq * diff * diff;
            }
        }
        
        return minSumSq;
    }
};