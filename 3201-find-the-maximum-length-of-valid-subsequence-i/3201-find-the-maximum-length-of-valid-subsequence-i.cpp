class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int desired, int curr) {
        if(curr == nums.size()) {
            return 0;
        }
        if(dp[curr][desired] != -1) {
            return dp[curr][desired];
        }
        int nonPick = solve(nums, dp, desired, curr+1);
        int pick = 0;
        if(nums[curr]%2 == desired) {
            pick = 1 + solve(nums, dp, !desired, curr+1);
        }
        return dp[curr][desired] = max(pick, nonPick);
    }
    
    int solve2(vector<int>& nums, int desired) {
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]%2 == desired) {
                ans++;
            }
        }
        return ans;
    }

    int maximumLength(vector<int>& nums) {
        vector<vector<int>> dp1(nums.size(), vector<int>(2, -1));
        vector<vector<int>> dp2(nums.size(), vector<int>(2, -1));
        int a = solve(nums, dp1, 1, 0);
        int b = solve(nums, dp2, 0, 0);
        int c = solve2(nums, 0);
        int d = solve2(nums, 1);
        return max(max(a, b), max(c, d));
    }
};