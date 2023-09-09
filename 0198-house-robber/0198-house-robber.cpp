class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++) {
            int pick=nums[i];
            if(i>=2) {
                pick += dp[i-2];
            }
            int nonPick = dp[i-1];
            dp[i] = max(pick, nonPick);
        }
        return dp[n-1];        
    }
};