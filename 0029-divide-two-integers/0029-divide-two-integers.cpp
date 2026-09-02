#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle 32-bit integer overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the quotient
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to prevent overflow during absolute value conversion
        long long abs_dividend = std::abs((long long)dividend);
        long long abs_divisor = std::abs((long long)divisor);
        long long quotient = 0;

        // Exponential search using bit manipulation
        while (abs_dividend >= abs_divisor) {
            long long temp_divisor = abs_divisor;
            long long multiple = 1;

            while (abs_dividend >= (temp_divisor << 1)) {
                temp_divisor <<= 1;
                multiple <<= 1;
            }

            abs_dividend -= temp_divisor;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};