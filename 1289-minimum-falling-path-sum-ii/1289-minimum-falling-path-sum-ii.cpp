class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), ans = INT_MAX;
        vector<int> prev(n, -1);
        vector<int> curr(n, -1);
        for(int i=0; i<n; i++) {
            prev[i] = grid[0][i];
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<n;j++) {
                int top = INT_MAX;
                for(int k = 0; k<n; k++) {
                    if(k==j) {
                        continue;
                    }
                    top = min(top, prev[k]);
                }                
                curr[j] = top + grid[i][j];
            }
            prev = curr;
        }
        for(int i = 0; i<n; i++) {
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};