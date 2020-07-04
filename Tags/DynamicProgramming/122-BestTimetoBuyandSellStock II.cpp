// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// keyword: dynamic programming / property of the question

// My Solution
// Standard dynamic programming, using the state transferring
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int MAX_N = 30000;
        int dp[MAX_N][2];
        // dp[n][0] means I do not have stock now at time n
        // dp[n][1] means I have stock at time n
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

// Referenced Solution
// Use the property of the question, without dp in fact, but more subtle
// A accumulative approach for solving the problem
// more explanation see https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/
// in Java
/*
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}
*/
