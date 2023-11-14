class Solution {
public:

    int solve(vector<int>& nums, vector<vector<int>>& dp, int n) {
        int mini = nums[0], maxi = nums[0];
        int ans = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i]<0) {
                swap(maxi, mini);
            }
            mini = min(nums[i]*mini, nums[i]);
            maxi = max(nums[i]*maxi, nums[i]);
            ans = max(ans, maxi);            
        }
        return ans;
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp;
        return solve(nums, dp, n);        
    }
};