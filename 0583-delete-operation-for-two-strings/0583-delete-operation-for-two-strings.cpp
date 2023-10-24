class Solution {
public:

    int solve(string word1, string word2, int n, int m) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int common = solve(word1,word2, n, m);
        int ans =  n+m - 2*common;
        return ans;
    }
};