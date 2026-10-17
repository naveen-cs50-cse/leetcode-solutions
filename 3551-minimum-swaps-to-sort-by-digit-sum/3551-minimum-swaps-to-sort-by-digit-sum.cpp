#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    // అంకెల మొత్తాన్ని (digit sum) లెక్కించడానికి ఒక హెల్పర్ ఫంక్షన్
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        
        // జోడీలను (pair) తయారు చేద్దాం: {digit_sum, original_value, original_index}
        // ఇక్కడ మనం ఒక కస్టమ్ స్ట్రక్చర్ లేదా వెక్టర్ ఆఫ్ వెక్టర్స్/పేర్స్ వాడవచ్చు.
        std::vector<std::pair<std::pair<int, int>, int>> items(n);
        for (int i = 0; i < n; ++i) {
            int dSum = getDigitSum(nums[i]);
            items[i] = {{dSum, nums[i]}, i};
        }
        
        // నియమాల ప్రకారం సార్ట్ చేద్దాం: 
        // 1. అంకెల మొత్తం (digit sum)
        // 2. సంఖ్య విలువ (value)
        std::sort(items.begin(), items.end());
        
        // సైకిల్ డిటెక్షన్ (Cycle Detection) ద్వారా కనీస స్వాప్స్ కనుగొనడం
        std::vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            // ఒకవేళ ఇది ఇప్పటికే విజిట్ చేయబడితే లేదా సరైన స్థానంలో ఉంటే దాటేయండి
            if (visited[i] || items[i].second == i) {
                continue;
            }
            
            // సైకిల్ పొడవును కనుగొనడం
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = items[curr].second;
                cycle_size++;
            }
            
            // సైకిల్ ఉంటే, స్వాప్స్ సంఖ్య = (సైకిల్ సైజు - 1)
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};