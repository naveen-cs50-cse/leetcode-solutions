#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";

        for (int i = 1; i < n; ++i) {
            string nextRes = "";
            int len = res.length();

            for (int j = 0; j < len; ++j) {
                int count = 1;

                // Count consecutive identical characters
                while (j + 1 < len && res[j] == res[j + 1]) {
                    count++;
                    j++;
                }

                // Append frequency followed by the character
                nextRes += to_string(count) + res[j];
            }

            res = nextRes;
        }

        return res;
    }
};