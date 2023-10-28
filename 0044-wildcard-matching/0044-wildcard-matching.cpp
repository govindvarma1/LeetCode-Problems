class Solution {
public:

    int solve(string s, string p, int n, int m) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;
        for(int j = 1; j<=m; j++) {
            if(p[j-1] != '*') {
                break;
            }
            dp[0][j] = 1;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*') {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        return solve(s, p, n, m);
    }
};