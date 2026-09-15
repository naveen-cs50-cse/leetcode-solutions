class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1; // Tracks the end index of the last chosen palindrome

        // Expand around centers (both odd and even lengths)
        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center / 2;
            int right = left + (center % 2);

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                
                // Check if valid length and non-overlapping with previously picked substring
                if (len >= k && left > last_end) {
                    count++;
                    last_end = right; // Update the boundary
                    break;            // Stop expanding this center (greedy choice)
                }
                
                // Optimization: stop expanding if length exceeds k + 1,
                // as any larger palindrome contains a sub-palindrome of length k or k + 1
                if (len > k + 1) break;

                left--;
                right++;
            }
        }

        return count;
    }
};