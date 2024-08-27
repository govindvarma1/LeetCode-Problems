class Triple {
    public:    
    int row, col, dist;
    Triple(int row,int col,int dist) {
        this->row = row;
        this->col = col;
        this->dist = dist;
    }
};

class Solution {
public:

    vector<int> delRow {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> delCol {0, 1, 1, 1, 0, -1, -1, -1};

    bool isPossible(int n, int m, int row, int col) {
        if(row>=0 && row<n && col>=0 && col<m) {
            return true;
        }
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<Triple> q;
        if(grid[0][0] == 0) {
            q.push({0, 0, 1});
        }
        while(!q.empty()) {
            auto [row, col, dist] = q.front();
            q.pop();
            if(row == n-1 && col == n-1) {
                return dist;
            }
            for(int i=0; i<8; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(isPossible(n, m, newRow, newCol) && !grid[newRow][newCol]) {
                    grid[newRow][newCol] = 1;
                    q.push({newRow, newCol, dist + 1});
                }
            }
        }
        return -1;
    }
};