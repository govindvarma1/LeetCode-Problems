class Solution {
public:

    bool isPossible(vector<vector<int>>& vis, int row, int col, int m, int n) {
        if(row >= 0 && row < m && col >= 0 && col < n && vis[row][col] == -1) {
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>>& vis, vector<vector<int>>& dp, int row, int col) {
        int m = vis.size(), n = vis[0].size();
        if(row == m - 1 && col == n - 1) {
            return 1;
        }
        vis[row][col] = 1;
        int res = 0;
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        if(isPossible(vis, row + 1, col, m, n)) {
            res += solve(vis, dp, row + 1, col);
        } 
        if(isPossible(vis, row, col + 1, m, n)) {
            res += solve(vis, dp, row, col + 1);
        }
        vis[row][col] = -1;
        return dp[row][col] = res;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> vis(m, vector<int>(n, -1));
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(vis, dp, 0, 0);
    }
};