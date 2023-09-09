class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j) {
        if(i==0 && j==0 && obstacleGrid[i][j]==0) {
            return 1;
        } else if((i<0 || j<0) || obstacleGrid[i][j]==1) {
            return 0;
        }
        int top=0;
        int left=0;
        if(i>0 && dp[i-1][j]!=-1) {
            top=dp[i-1][j];
        } else {
            top=solve(obstacleGrid, dp, i-1, j);
        }
        if(j>0 && dp[i][j-1]!=-1) {
            left=dp[i][j-1];
        } else {
            left=solve(obstacleGrid, dp, i, j-1);
        }
        return dp[i][j]=top+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(obstacleGrid, dp, n-1, m-1);        
    }
};