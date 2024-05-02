class Solution {
public:

    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void addCombination(vector<string>& ans,string& digits, string s, int ind) {
        if(ind >= digits.length()) {
            ans.push_back(s);
            return;
        }
        int num = digits[ind] - '2';
        for(int i=0; i<letters[num].length(); i++) {
            addCombination(ans, digits, s + letters[num][i], ind + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) {
            return {};
        }
        vector<string> ans;
        addCombination(ans, digits, "", 0);
        return ans;
    }
};