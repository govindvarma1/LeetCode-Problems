class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        for(int i=0; i<9; i++) {
            if(board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }
        int nRow = row/3, nCol = col/3;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[nRow*3+i][nCol*3+j] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(int k=1; k<=9; k++) {
                        if(isSafe(board, i, j, k+'0')) {
                            board[i][j] = k+'0';
                            if(solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);        
    }
};