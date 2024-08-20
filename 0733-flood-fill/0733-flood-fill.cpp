class Solution {
public:

    vector<int> delRow{-1, 0, 1, 0};
    vector<int> delCol{0, 1, 0, -1};

    bool isPossible(vector<vector<int>>& image, int sr, int sc) {
        int n = image.size();
        int m = image[0].size();
        if(sr>=0 && sr<n && sc>=0 && sc<m) {
            return true;
        }
        return false;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int originalColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            image[row][col] = color;
            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(isPossible(image, newRow, newCol) && image[newRow][newCol] == originalColor && vis[newRow][newCol] == 0) {
                    vis[newRow][newCol] = 1;
                    cout<<"Yes"<<endl;
                    q.push({newRow, newCol});
                }
            }
        }
        return image;
    }
};