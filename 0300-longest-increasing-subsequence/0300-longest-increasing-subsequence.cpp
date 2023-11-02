class Solution {
public:

    int solve(int i, int j, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if(i==n) {
            return 0;
        }
        if(dp[i][j+1] != -1) {
            return dp[i][j+1];
        }
        int len = solve(i+1, j, n, nums, dp);
        if(j== -1 || nums[j] < nums[i]) {
            len = max(len, 1 + solve(i+1, i, n, nums, dp));
        } 
        return dp[i][j+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0,-1, n, nums, dp);
    }
};