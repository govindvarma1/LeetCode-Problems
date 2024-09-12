class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        vector<string> rows(numRows, "");
        int n = s.size(), row = 0, ind = 0;
        while(ind < n) {
            while(ind < n && row < numRows) {
                rows[row].push_back(s[ind]);
                row++;
                ind++;
            }
            row-=2;
            while(ind < n && row > 0) {
                rows[row].push_back(s[ind]);
                row--;
                ind++;
            }
        }
        string ans = "";
        for(int i=0; i<numRows; i++) {
            ans += rows[i];
        }
        return ans;
    }
};