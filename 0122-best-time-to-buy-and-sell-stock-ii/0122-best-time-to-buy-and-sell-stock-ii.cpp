class Solution {
public:
    int solve(int n, vector<int>& prices) {
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int i=n-1; i>=0; i--) {
            for(int buy = 0; buy<=1; buy++) {
                int profit = 0;
                if(buy == 0) {
                    int sell = dp[i+1][0];
                    int notSell =  -1*prices[i] + dp[i+1][1];
                    profit =  max(sell, notSell);
                } else {
                    int pick = dp[i+1][1];
                    int notPick = prices[i] +  dp[i][0];
                    profit = max(pick, notPick);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(n,prices);
    }
};
