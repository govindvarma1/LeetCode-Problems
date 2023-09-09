class Solution {
public:
    int solve(vector<vector<int>>& grid,int n,int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int top=INT_MAX, left=INT_MAX;
                if(i!=0 || j!=0) {
                    if(i>0) {
                        top=dp[i-1][j];
                    }
                    if(j>0) {
                        left=dp[i][j-1];
                    }
                    dp[i][j]=grid[i][j]+min(top, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        return solve(grid,n,m);
    }
};