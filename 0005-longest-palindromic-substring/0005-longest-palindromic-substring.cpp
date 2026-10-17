class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {

            // Case 1: Odd-length palindrome
            int left = i;
            int right = i;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {

                int len = right - left + 1;

                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }

                left--;
                right++;
            }

            // Case 2: Even-length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {

                int len = right - left + 1;

                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};