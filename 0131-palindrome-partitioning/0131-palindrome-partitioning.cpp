class Solution {
public:

    bool isPalindrome(string& s, int start, int end) {
        while(start<=end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++; end--;
        }
        return true;
    }

    void addPartitions(vector<vector<string>>& ans,vector<string> arr, string s, int start) {
        if(start >= s.size()) {
            ans.push_back(arr);
            return;
        }
        for(int end=start; end<s.size(); end++) {
            if(isPalindrome(s, start, end)) {
                arr.push_back(s.substr(start, end-start+1));
                addPartitions(ans, arr, s, end+1);
                arr.pop_back();
            } 
        }   
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;
        addPartitions(ans, arr, s, 0);
        return ans;        
    }
};