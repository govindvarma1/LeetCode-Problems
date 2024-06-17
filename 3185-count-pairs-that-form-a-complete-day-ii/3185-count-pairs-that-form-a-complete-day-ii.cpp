class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        map<int, int> mp;
        int n = hours.size();
        long long ans = 0;
        for(int i=0; i<n; i++) {
            int num = hours[i]%24;
            if(num == 0) {
                if(mp.find(0) != mp.end()) {
                    ans += mp[0];
                }
            } else {
                int toBeFound = 24 - num;
                if(mp.find(toBeFound) != mp.end()) {
                    ans += mp[toBeFound];
                }
            }
            mp[num]++;
        }
        return ans;
    }
};