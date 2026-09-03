#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        // Count frequency of each word in `words`
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        // Run sliding window starting at each offset from 0 to wordLen - 1
        for (int i = 0; i < wordLen; ++i) {
            unordered_map<string, int> seen;
            int left = i;
            int count = 0;

            for (int right = i; right + wordLen <= sLen; right += wordLen) {
                string sub = s.substr(right, wordLen);

                if (wordCount.count(sub)) {
                    seen[sub]++;
                    count++;

                    // If a word occurs more times than required, slide `left` forward
                    while (seen[sub] > wordCount[sub]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If we matched all words, record the start index
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window if word is not in `words`
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};