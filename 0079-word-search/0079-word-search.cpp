class Solution {
public:

    vector<int> delrow{-1, 0, 1, 0}, delcol{0, 1, 0, -1};

    bool findIfExist(vector<vector<char>>& board, string word, int ind, int row, int col) {
        int m = board.size(), n = board[0].size();
        if(ind == word.length()) {
            return true;
        }
        if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] == '!' || board[row][col] != word[ind]) {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '!';
        bool result = false;
        for(int i=0; i<4; i++) {
            int newRow = row + delrow[i];
            int newCol = col + delcol[i];
            result = result || findIfExist(board, word, ind+1, newRow, newCol);
            
        }
        board[row][col] = temp;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j =0; j<n; j++) {
                if(word[0] == board[i][j] ) {
                    if(findIfExist(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};