class Solution {
public:

    int solve(vector<int>& arr, vector<int>& dp, int i, int n, int k) {
        for(int i=n-1; i>=0; i--) {
            int maxi = -1, ans = -1;
            for(int ind = 0; ind<k && i+ind<n; ind++) {
                maxi = max(maxi, arr[i+ind]);
                ans = max(ans, maxi*(ind+1) + dp[ind+i+1]);
            }     
            dp[i] = ans;
        }
        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        return solve(arr, dp, 0, n, k);
    }
};