// https://leetcode.com/problems/longest-palindromic-substring/
// My Solution (referenced to other solutions)
// Keyword: Dynamic Programming, interval dynamic programming (different from common 1D dynamic programming)

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        int len = s.size();
        vector<vector<bool>>dp(len);
        for (int i = 0;i < len; i++) {
            dp[i] = vector<bool>(len, 0);
            dp[i][i] = 1;
        }

        for (int i = 0; i < len - 1; i++) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int i = 2; i < len; i++) {
            for (int j = 0; j + i < len; j++) {
                dp[j][j + i] = (dp[j + 1][j + i - 1] && (s[j] == s[j + i]));
            }
        }

        int max_interval = -1;
        int left = -1, right = -1;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (dp[i][j]) {
                    if (max_interval < j - i) {
                        max_interval = j - i;
                        left = i;
                        right = j;
                    }
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};
