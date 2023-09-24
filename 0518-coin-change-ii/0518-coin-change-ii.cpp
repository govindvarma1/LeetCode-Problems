class Solution {
public:

    int solve(vector<int>& coins, vector<vector<int>>& dp,int target, int index) {
        if(target == 0) {
            return 1;
        }
        if(index<0 || target<0) {
            return 0;
        }
        if(dp[index][target] !=-1) {
            return dp[index][target];
        }
        int pick = 0;
        int notPick = solve(coins, dp, target, index-1);
        if(coins[index]<=target) {
            pick = solve(coins, dp, target-coins[index], index);
        }
        return dp[index][target] =pick+notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(coins, dp, amount, n-1);        
    }
};