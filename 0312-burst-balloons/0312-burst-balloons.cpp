class Solution {
public:

    int maxCoins(vector<int>& nums) {
        int n = nums.size(); 
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));        
        for(int i=n; i>=1; i--) {
            for(int j=i; j<=n; j++) {
                int res = INT_MIN;
                for(int k=i; k<=j; k++) {
                    int ans =  nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    res = max(ans, res);
                }
                dp[i][j] = res;
            } 
        }
        return dp[1][n];
    }
};