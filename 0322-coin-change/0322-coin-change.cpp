class Solution {
public:
    
    int solve(vector<int>& coins, vector<vector<int>>& dp, int index, int amount) {
        if(index == 0) {
            if(amount % coins[0] ==0) {
                return amount/coins[0];
            } else {
                return 1e9;
            }
        }
        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }
        int notTake = solve(coins, dp, index-1, amount);
        int take =1e9;
        if(coins[index] <= amount) {
            take = 1+ solve(coins, dp, index, amount-coins[index]);
        }
        return dp[index][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>  dp(n, vector<int>(amount+1, -1));
        int ans = solve(coins, dp, n-1, amount);
        if(ans == 1e9) {
            return -1;
        } else {
            return ans;
        }
    }
};