
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
// TWO THINGS
// EITHER OF TYPE ABA
// for aba i will go both left & right till I can go
// OR BBBBBBB (so for bbbbb ) type, i will go in one direction only say right,,... (as this will encounter all possibilitues)
        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.size(); i++) {
            // Odd length palindrome (center at i)
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left; //i will use start instead of lest & right, (as left,right change -- ++)
                }
                left--;
                right++;
            }

            // Even length palindrome (center between i and i+1)
            // stuff like aaa

            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLength);
    }
};
