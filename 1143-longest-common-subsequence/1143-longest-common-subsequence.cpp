class Solution {
public:

    int solve(string text1, string text2,vector<vector<int>>& dp, int n, int m) {
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m;j++) {
                if(text1[i] == text2[j]) {
                    int prev = 1;
                    if(i>0 && j>0) {
                        prev += dp[i-1][j-1];
                    }
                    dp[i][j] = prev;
                } else {
                    int one =0 , two =0;
                    if(i>0) {
                        one = dp[i-1][j];
                    }
                    if(j>0) {
                        two = dp[i][j-1];
                    }
                    dp[i][j] = max(one, two);
                }
            
            }
        }
        return dp[n-1][m-1];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(text1, text2,dp, n1 , n2);
    }
};