// https://leetcode.com/problems/house-robber-ii/
// My Solution

// Keyword: Dynamic Programming

// The trick of circle lies in break it into two lines.
// If you count the first element in, then just calculate the result without the last element.
// Similarly, if you count the last element in, then just calculate the result without the first element.

class Solution {
public:
    int rob_line(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int result = dp[nums.size() - 1];
        return result;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> front(nums.begin(), nums.end() - 1);
        vector<int> back (nums.begin() + 1, nums.end());
        return max(rob_line(front), rob_line(back));
    }
};
