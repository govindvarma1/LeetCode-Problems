class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int n = s.size();
        string word = "", ans = "";
        for(int i=0; i<n; i++) {
            if(s[i] ==' ' && word.size()>0) {
                arr.push_back(word);
                word = "";
            } else if(s[i] != ' ') {
                word += s[i];
            }
        }
        if(word != "") {
            // cout<<word<<endl;
            arr.push_back(word);
        }
        for(int j=arr.size()-1; j>0; j--) {
            ans += arr[j] + ' ';
        }
        ans+=arr[0];
        return ans;      
    }
};