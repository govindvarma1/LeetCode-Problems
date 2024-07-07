class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = n-1, j = m-1, ans = 0;
        while(j>=0 && i>=0) {
            if(g[i] <= s[j]) {
                ans++;
                j--;
                i--;
            } else {
                i--;
            }
        }
        return ans;
    }
};