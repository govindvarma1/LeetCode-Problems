class Solution {
public:

    vector<vector<int>> create(int numRows) {
        vector<vector<int>> triangle;
        for(int i=1; i<=numRows; i++) {
            vector<int> temp(i, 0);
            temp[0] = 1;
            temp[i - 1] = 1;
            triangle.push_back(temp);
        }
        return triangle;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle= create(numRows);
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<triangle[i].size(); j++) {
                if(triangle[i][j] == 0) {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }
            }
        }
        return triangle;
    }
};