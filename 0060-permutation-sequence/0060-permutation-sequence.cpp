#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> numbers;
        std::vector<int> factorial(n, 1);
        
        // Calculate factorials and initialize list of available numbers
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }

        // Convert k to 0-based index
        k--;

        std::string result = "";
        for (int i = n; i >= 1; i--) {
            // Determine the index of the next digit
            int index = k / factorial[i - 1];
            result += std::to_string(numbers[index]);

            // Remove used digit and update k
            numbers.erase(numbers.begin() + index);
            k %= factorial[i - 1];
        }

        return result;
    }
};