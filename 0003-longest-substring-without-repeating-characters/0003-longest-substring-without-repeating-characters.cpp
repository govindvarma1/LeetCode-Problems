class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int right = 0, left = 0;
        map<char, int> mpp;
        while(right < n) {
            if(mpp.find(s[right]) != mpp.end()) {
                left = max(mpp[s[right]] + 1, left);
            }
            ans = max(right - left + 1, ans);
            mpp[s[right]] = right;
            right = right + 1;
        }
        return ans;
    }
};