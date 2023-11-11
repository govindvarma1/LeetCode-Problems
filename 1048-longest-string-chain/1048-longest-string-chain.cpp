class Solution {
public:

    bool compare(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        if(n != 1+m) {
            return false;
        }
        int i=0, j=0;
        while(i<n) {
            if(j<m && word1[i] == word2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if(i == n && j==m) {
            return true;
        }
        return false;
    }

    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        int maxi = 1;
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(compare(words[i], words[j]) && dp[i] < 1+ dp[j]) {
                    dp[i] = 1+dp[j];
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};