class Solution {
public:
    
    int solve(string str1, string str2, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int ans = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1; j<=n-i+1; j++) {
                if(str1[i-1] == str2[j-1]) {
                    if(n-i == j-1) {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    } else {
                        dp[i][j] = 2 + dp[i-1][j-1];
                    }
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n==1) {
            return 1;
        }
        string str1 = s;
        string str2 = "";
        for(int i=n-1; i>=0;i--) {
            str2+=s[i];
        }
        return solve(str1, str2, n);
                
    }
};