class Solution {
public:
    void solve(string &num, vector<string>& ans, string curr, int ind, int target, long prev, long curr_no) {
        if (ind == num.size()) {
            if (curr_no == target) {
                ans.push_back(curr);
            }
            return;
        }
        
        for (int i = ind; i < num.size(); ++i) {
            if (i != ind && num[ind] == '0') break;
            
            string part = num.substr(ind, i - ind + 1);
            long currentNumber = stol(part);

            if (ind == 0) {
                solve(num, ans, part, i + 1, target, currentNumber, currentNumber);
            } else {
                solve(num, ans, curr + '+' + part, i + 1, target, currentNumber, curr_no + currentNumber);
                solve(num, ans, curr + '-' + part, i + 1, target, -currentNumber, curr_no - currentNumber);
                solve(num, ans, curr + '*' + part, i + 1, target, prev * currentNumber, curr_no - prev + (prev * currentNumber));
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, ans, "", 0, target, 0, 0);
        return ans;
    }
};
