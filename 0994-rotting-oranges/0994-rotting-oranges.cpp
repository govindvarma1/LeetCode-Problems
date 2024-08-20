class Oranges {
public:
    int row, col, depth;
    Oranges (int row,int col,int depth) {
        this->row = row;
        this->col = col;
        this->depth = depth;
    }
};

class Solution {
public:

    bool isPossible(vector<vector<int>>& grid, int row, int col) {
        if(row >= 0 && row < grid.size() && col >=0 && col < grid[0].size()) {
            return true;
        }
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int depth = 0;
        vector<int> delRow{-1, 0, 1, 0};
        vector<int> delCol{0, 1, 0, -1};
        queue<Oranges> q;
        for(int i=0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }     
        while(!q.empty()) {
            auto [row, col, dep] = q.front();
            q.pop();
            depth = dep;
            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(isPossible(grid, newRow, newCol) && grid[newRow][newCol] == 1) {
                    q.push({newRow, newCol, dep + 1});
                    grid[newRow][newCol] = 2;
                }
            }
        }  
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return depth;
    }
};