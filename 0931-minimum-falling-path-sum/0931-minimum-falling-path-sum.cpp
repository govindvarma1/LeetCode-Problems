class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        //memoisation approach does not work and it gives tle
        int n = matrix.size(), ans=1e9;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int k=0;k<n;k++) {
            dp[0][k]=matrix[0][k];
        }
        for(int i=1;i<n; i++) {
            for(int j=0;j<n;j++) {
                int top=dp[i-1][j];
                int topRight =1e8;
                int topLeft = 1e8;                  
                if(j>0) {
                    topLeft = dp[i-1][j-1];
                }
                if(j<n-1) {
                    topRight = dp[i-1][j+1];
                }
                dp[i][j] = matrix[i][j] + min(top, min(topLeft, topRight));
            }
        }
        for(int i=0;i<n;i++) {
            ans = min(ans, dp[n-1][i]);
        }
        return ans;   
    }
};