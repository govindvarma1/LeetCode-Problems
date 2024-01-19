class Solution {
public:
    //solved problem using prefix and sufix approach
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n==1) {
            return 1;
        }
        vector<pair<int, int>> bsum(n, {0, 0}), fsum(n, {0, 0});
        int ans = 0;
        if((n-1) % 2 == 0) {
            bsum[n-1].first = nums[n-1];
        } else {
            bsum[n-1].second = nums[n-1];
        }
        for(int i = n-2; i >= 0; i--) {
            if(i%2 == 0) {
                bsum[i].first = bsum[i+1].first + nums[i];
                bsum[i].second = bsum[i+1].second;
            } else {
                bsum[i].first = bsum[i+1].first;
                bsum[i].second = bsum[i+1].second + nums[i];
            }
        }
        fsum[0].first = nums[0];
        for(int i = 1; i < n; i++) {
            if(i%2 == 0) {
                fsum[i].first = fsum[i-1].first + nums[i];
                fsum[i].second = fsum[i-1].second;
            } else {
                fsum[i].first = fsum[i-1].first;
                fsum[i].second = fsum[i-1].second + nums[i];
            }
        }
        for(int i=0; i<n; i++) {
            if(i==0 && i+1<n && bsum[i+1].first == bsum[i+1].second) {
                ans++;
            } else if(i==n-1 && i>=0 && fsum[i-1].first == fsum[i-1].second) {
                ans++;
            } else if(i!=0 && i!=n-1) {
                int odd = fsum[i-1].second + bsum[i+1].first;
                int even = fsum[i-1].first + bsum[i+1].second;
                if(odd == even) {
                    ans++;
                }
            }
        }
        return ans;
    }
};