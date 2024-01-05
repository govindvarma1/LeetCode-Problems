class Solution {
public:
    int n;
    bool isPalindrome(string& s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }

    int solve(string& s, vector<int>& dp, int i) {
        if(i==n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int mini = INT_MAX;
        for(int k=i; k<n; k++) {
            if(isPalindrome(s, i, k)) {
                int ans = 1 + solve(s, dp, k+1);
                mini = min(mini, ans);            
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        n = s.size();
        if(n==1) {
            return 0;
        }
        vector<int> dp(n, -1);
        return solve(s, dp, 0) - 1;
        
    }
};