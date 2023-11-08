class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n+1, 1), index(n, -1);
        int max_len = 1;
        int idx = 0;
        for(int i=1; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[i]%nums[j] == 0) {
                    if(dp[i]<1+dp[j]) {
                        dp[i] = 1 + dp[j];
                        index[i] = j;
                        if(max_len<dp[i]) {
                            idx = i;
                            max_len = dp[i];
                        }
                    }
                }
            }
        }
        vector<int> ans;
        int j = idx;
        while(j>=0) {
            ans.push_back(nums[j]);
            j=index[j];
        }
        return ans;
    }
};