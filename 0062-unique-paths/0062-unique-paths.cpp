class Solution {
public:

    int solve(vector<vector<int>>& dp, int n, int m) {
        dp[0][0]=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i!=0 || j!=0) {
                    if(i>0) {
                        dp[i][j]+=dp[i-1][j];
                    } 
                    if(j>0) {
                        dp[i][j]+=dp[i][j-1];
                    }
                }   
            }
        }
        return dp[n-1][m-1];
        
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        return solve(dp, n, m);                 
    }
};