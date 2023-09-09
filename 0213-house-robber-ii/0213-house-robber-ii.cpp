class Solution {
public:

    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) {
            return nums[0];
        }
        vector<int> dp(n, -1);   
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++) {
            int pick = nums[i];
            int nonPick = dp[i-1];
            if(i>1) {
                pick+=dp[i-2];
            }            
            dp[i]=max(pick, nonPick);
        }  
        int one=dp[n-2];
        dp.assign(n, -1);
        dp[1]=nums[1];
        for(int i=2;i<n;i++) {
            int pick = nums[i];
            int nonPick = dp[i-1];
            if(i>2) {
                pick+=dp[i-2];
            }            
            dp[i]=max(pick, nonPick);
        }  
        int two=dp[n-1];
        return max(one, two);
    }
};