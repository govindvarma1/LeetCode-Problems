class Solution {
public:

    int solve(int k, int n, vector<int>& prices) {
        vector<vector<int>> prev(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        for(int i= n-1; i>=0; i--) {
            for(int buy = 0; buy<=1; buy++) {
                for(int cap = 1; cap<=k; cap++) {
                    if(buy == 1) {
                        curr[buy][cap] = max(-prices[i] + prev[0][cap], prev[1][cap]);
                    } else {
                        curr[buy][cap] = max(prices[i] + prev[1][cap-1], prev[0][cap]);
                    }
                }
            }
            prev = curr;
        }
        return prev[1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solve(k, n, prices);        
    }
};