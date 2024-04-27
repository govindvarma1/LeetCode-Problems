class Solution {
public:

    void generate(vector<string>& ans,string s, int open, int close) {
        if(close == 0) {
            ans.push_back(s);
            return;
        }
        if(open>0) {
            string temp = s + "(";
            generate(ans, temp, open-1, close);
        }
        if(close > open) {
            string temp = s + ")";
            generate(ans, temp, open, close-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        int open = n, close = n;
        generate(ans,s, open, close);
        return ans;
    }
};