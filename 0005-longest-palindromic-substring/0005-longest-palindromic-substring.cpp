class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0, start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                int len = j - i + 1;

                // Only check if current length is greater than maxLen
                if (len <= maxLen) break;

                // Check if substring s[i..j] is a palindrome
                bool isPalindrome = true;
                for (int l = i, r = j; l < r; l++, r--) {
                    if (s[l] != s[r]) {
                        isPalindrome = false;
                        break;
                    }
                }

                if (isPalindrome) {
                    maxLen = len;
                    start = i;
                    break; // No need to check smaller j for same i
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
