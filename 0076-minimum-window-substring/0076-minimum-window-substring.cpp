class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        // Frequency map for characters in t
        vector<int> tFreq(128, 0);
        for (char c : t) {
            tFreq[c]++;
        }

        int requiredChars = t.length();
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIdx = -1;

        // Expand the right pointer to expand the sliding window
        while (right < s.length()) {
            char rightChar = s[right];
            
            // If rightChar is needed, reduce the count of required characters
            if (tFreq[rightChar] > 0) {
                requiredChars--;
            }
            // Decrement frequency in map (can become negative for surplus characters)
            tFreq[rightChar]--;
            right++;

            // Shrink the window from the left once all characters are matched
            while (requiredChars == 0) {
                int currentLen = right - left;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    startIdx = left;
                }

                char leftChar = s[left];
                tFreq[leftChar]++;
                
                // If leftChar is part of required target frequencies, increment requiredChars
                if (tFreq[leftChar] > 0) {
                    requiredChars++;
                }
                left++;
            }
        }

        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};