// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// keyword: dynamic programming / property of the question

// My Solution
// Standard dynamic programming, using the state transferring
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int* dp = new int[prices.size()];
        dp[0] = 0;
        int now_min = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            now_min = min(prices[i], now_min);
            dp[i] = max(dp[i - 1], prices[i] - now_min);
        }
        int result = dp[prices.size() - 1];
        delete[]dp;
        return result;
    }
};

// Referenced Solution
// Use the property of the question, without dp in fact, but more subtle
// in Java
/*
public class Solution {
    public int maxProfit(int prices[]) {
        int minprice = Integer.MAX_VALUE;
        int maxprofit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
}
*/
