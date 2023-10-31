class Solution {
public:

    int solve(int n, vector<int>& prices) {
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy == 1) {
                    dp[i][1] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                } else {
                    dp[i][0] = max(prices[i]+dp[i+2][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(n, prices);
    }
};