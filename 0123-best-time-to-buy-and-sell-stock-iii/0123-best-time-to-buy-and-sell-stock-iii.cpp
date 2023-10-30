class Solution {
public:
    
    int solve(int i, int n, int buy, int cap,vector<vector<vector<int>>>& dp, vector<int>& prices) {
        for(int ind = n-1; ind>=0; ind--) {
            for(int buy = 0; buy<=1; buy++) {
                for(int cap = 1; cap<=2; cap++) {
                    if(buy == 1) {
                        dp[ind][buy][cap] = max( -prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
                    }
                     else {
                        dp[ind][buy][cap] = max( prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        int ans = solve(0, n, 1, 2, dp, prices);
        return ans;
    }
};