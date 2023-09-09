class Solution {
public:

    int solve(vector<vector<int>>& triangle,vector<vector<int>>& dp, int i, int j, int n){
        if(i==n-1) {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int down = INT_MAX;
        int down_right = INT_MAX;
        down = solve(triangle, dp, i+1, j, n);
        down_right = solve(triangle, dp, i+1, j+1, n);
        return dp[i][j] = triangle[i][j] + min(down, down_right);

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        for(int i=1;i<=n;i++) {
            vector<int> array(i, -1);
            dp.push_back(array);
        }
        return solve(triangle, dp, 0, 0, n);
    }
};