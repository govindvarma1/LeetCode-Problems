class Solution {
public:

    int solve(int k, int n, vector<int>& prices) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int i= n-1; i>=0; i--) {
            for(int buy = 0; buy<=1; buy++) {
                for(int cap = 1; cap<=k; cap++) {
                    if(buy == 1) {
                        dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    } else {
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solve(k, n, prices);        
    }
};