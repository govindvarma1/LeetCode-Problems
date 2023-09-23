class Solution {
public:

    int solve(vector<int>& nums,vector<vector<int>>& dp, int target, int index) {
        if(index == 0) {
            if(target ==0 && nums[0] == 0) {
                return 2;
            } 
            if(target == 0 || nums[0] == target) {
                return 1;
            }
            return 0;
        }
        if(dp[index][target] != -1) {
            return dp[index][target];
        }
        int notTake = solve(nums, dp, target, index-1);
        int take = 0;
        if(target>= nums[index]) {
            take = solve(nums, dp, target - nums[index], index -1);
        }
        return dp[index][target] = notTake + take;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            totalSum+= nums[i];
        }        
        if(totalSum < target) {
            return 0;
        }
        if((totalSum -target)%2 == 1) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>((totalSum-target)/2+1, -1));
        return solve(nums, dp, (totalSum-target)/2, n-1);
    }
};