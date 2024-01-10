class Solution {
public:

    int n, m;
    vector<int> delrow{-1, 0, 1, 0};
    vector<int> delcol{0, 1, 0, -1};

    bool isPossible(int i, int j) {
        if(i>=0 && i<n && j>=0 && j<m) {
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col, int prev) {
        if(dp[row][col] !=-1) {
            return dp[row][col];
        }
        int maxi = 1;
        for(int k=0; k<4; k++) {
            int newRow = delrow[k] + row;
            int newCol = delcol[k] + col;
            if(isPossible(newRow, newCol) && prev < matrix[newRow][newCol]) {
                maxi = max(maxi, 1 + solve(matrix, dp, newRow, newCol, matrix[newRow][newCol]));
            }
        }
        return dp[row][col] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans = max(ans , solve(matrix, dp, i, j, matrix[i][j]));
            }
        }
        return ans;
    }
};