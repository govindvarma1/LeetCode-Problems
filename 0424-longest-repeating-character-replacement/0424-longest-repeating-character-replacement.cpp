class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0, maxF = 0;
        int ans = 0;
        vector<int> count(26, 0);
        while(right < n) {
            count[s[right] - 'A']++;
            maxF = max(maxF, count[s[right] - 'A']);
            int windowLength = right - left + 1;
            if(windowLength - maxF > k) {
                count[s[left] - 'A']--;
                left++;
            } else {
                ans = max(ans, windowLength);
            }
            right++;
        }  
        return ans;
    }
};