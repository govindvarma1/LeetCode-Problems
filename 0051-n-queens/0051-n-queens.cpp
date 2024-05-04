class Solution {
public:

    void fill(vector<vector<string>>& ans, vector<vector<int>>& placed) {
        int n = placed.size();
        vector<string> queens;
        for(int row = 0; row < n; row++) {
            string s = "";
            for(int col = 0; col<n; col++) {
                if(placed[row][col] == 1) {
                    s += 'Q';
                } else {
                    s += '.';
                }
            }
            queens.push_back(s);
        }
        ans.push_back(queens);
    }

    bool isSafe(vector<vector<int>>& placed, int row, int col) {
        int x = row;
        int y = col;
        int n = placed.size();
        while(y >= 0) {
            if(placed[x][y] == 1) {
                return false;
            }
            y--;            
        }
        x = row;
        y = col;
        while(x>=0 && y>=0) {
            if(placed[x][y] == 1) {
                return false;
            }
            x--;
            y--;
        }
        x = row;
        y = col;
        while(x < n && y >= 0) {
            if(placed[x][y] == 1) {
                return false;
            }
            x++;
            y--;
        }
        return true;        
    }

    void solve(vector<vector<string>>& ans, vector<vector<int>>& placed, int col){
        int n = placed.size();
        if(n <= col) {
            fill(ans, placed);
            return;
        }
        for(int row = 0; row < n; row++) {
            if(isSafe(placed, row, col)) {
                placed[row][col] = 1;
                solve(ans, placed, col+1);
                placed[row][col] = 0;
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> placed(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(ans, placed,0);
        return ans;
    }
};