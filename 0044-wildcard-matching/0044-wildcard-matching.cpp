class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0;
        int match = 0, starIdx = -1;
        int sLen = s.length(), pLen = p.length();

        while (sIdx < sLen) {
            // Case 1: Matching characters or '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Case 2: Encountered '*'
            else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                match = sIdx;
                pIdx++;
            }
            // Case 3: Mismatch occurred, but a previous '*' was found
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                match++;
                sIdx = match;
            }
            // Case 4: Mismatch with no preceding '*'
            else {
                return false;
            }
        }

        // Consume remaining trailing '*' in pattern
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};