class Solution {
public:

    int solve(vector<int>& nums, vector<int>& dp, int ind) {
        if(ind >= nums.size() - 1) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        int mini = INT_MAX;
        for(int i = 1; i <= nums[ind]; i++) {
            if(i < nums.size()) {
                int result = solve(nums, dp, i + ind);
                if(result != INT_MAX) {
                    mini = min(mini, 1 + result);
                }
            }
        }
        return dp[ind] = mini;
    } 

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, dp, 0);
    }
};

