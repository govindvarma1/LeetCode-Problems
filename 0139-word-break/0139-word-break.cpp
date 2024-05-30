class Solution {
public:

    bool findString(string& sub_str, vector<string>& wordDict) {
        for(int i=0; i<wordDict.size(); i++) {
            if(wordDict[i] == sub_str) {
                return true;
            }
        }
        return false;
    }

    bool isValid(string& s, vector<vector<int>>& dp, vector<string>& wordDict, int start, int end) {
        if(end >= s.length()) {
            string sub_str = s.substr(start, end-start);
            if(start == end || findString(sub_str, wordDict)) {
                return true;
            } 
            return false;
        }
        if(dp[start][end] != -1) {
            return dp[start][end];
        }
        bool result = false;
        string sub_str = s.substr(start, end-start+1);
        if(findString(sub_str, wordDict)) {
            result = result || isValid(s, dp, wordDict, end+1, end+1);
        }
        result = result || isValid(s, dp, wordDict, start, end+1);
        dp[start][end] = result;
        return result;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return isValid(s, dp, wordDict, 0, 0);
    }
};