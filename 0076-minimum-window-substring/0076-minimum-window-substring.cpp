class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minLen = 1e9, startInd = -1;
        int cnt = 0, left = 0, right = 0;
        map<char, int> mpp;
        for(int k=0; k<m; k++) {
            mpp[t[k]]++;
        }
        while(right < n) {
            if(mpp[s[right]] > 0) {
                cnt++;
            }
            mpp[s[right]]--;
            while(cnt == m) {
                if(right - left + 1 < minLen) {
                    startInd = left;
                    minLen = right - left + 1;
                }
                mpp[s[left]]++;
                if(mpp[s[left]] > 0) {
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return startInd == -1 ? "" : s.substr(startInd, minLen);
    }
};