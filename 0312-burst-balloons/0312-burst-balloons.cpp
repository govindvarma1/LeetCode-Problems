class Solution {
public:

    int solve(vector<int>& nums,vector<vector<int>>& dp, int i, int j) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] !=-1) {
            return dp[i][j];
        }
        int mixi = INT_MIN;
        for(int k=i; k<=j; k++) {
            int ans = nums[i-1]*nums[k]*nums[j+1] + solve(nums,dp, i, k-1) + solve(nums, dp, k+1, j);
            mixi = max(mixi, ans);
        }
        return dp[i][j] = mixi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size(); 
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(nums, dp, 1, n);        
    }
};