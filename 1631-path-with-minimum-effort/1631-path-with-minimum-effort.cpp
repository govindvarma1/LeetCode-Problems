class Triple {
    public:
    int diff, row, col;
    Triple(int diff, int row, int col) {
        this->diff = diff;
        this->row = row;
        this->col = col;
    }

    bool operator>(const Triple& other) const {
        return this->diff > other.diff;
    }
};

class Solution {
public:

    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, 1, 0, -1};

    bool isPossible(int n, int m, int row, int col) {
        if(row>=0 && row<n && col>=0 && col<m) {
            return true;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<Triple, vector<Triple>, greater<Triple>> pq;
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        pq.push(Triple(0, 0, 0));
        while(!pq.empty()) {
            auto [diff, row, col] = pq.top();
            pq.pop();
            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(isPossible(n, m, newRow, newCol)) {
                    int newDiff = max(abs(heights[row][col] - heights[newRow][newCol]), diff);
                    if(newDiff < effort[newRow][newCol]) {   
                        effort[newRow][newCol] = newDiff;
                        pq.push(Triple(newDiff, newRow, newCol));
                    }
                }
            }
        }
        return effort[n-1][m-1];
    }
};