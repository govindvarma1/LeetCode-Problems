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

    void addPartitions(vector<vector<string>>& ans,vector<string> arr, string s, int start, int end) {
        if(end >= s.size()) {
            if(start != end && isPalindrome(s, start, end-1)) {
                arr.push_back(s.substr(start, end-start));
                ans.push_back(arr);
            }
            return;
        }
        if(isPalindrome(s, start, end)) {
            arr.push_back(s.substr(start, end-start+1));
            addPartitions(ans, arr, s, end+1, end+1);
            arr.pop_back();
        } 
        addPartitions(ans, arr, s, start, end+1);
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;
        addPartitions(ans, arr, s, 0, 0);
        return ans;        
    }
};