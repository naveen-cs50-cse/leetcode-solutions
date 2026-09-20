class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            int reversed_alphabet_index = 26 - (s[i] - 'a');
            int string_index = i + 1; // 1-indexed
            total += reversed_alphabet_index * string_index;
        }
        return total;
    }
};