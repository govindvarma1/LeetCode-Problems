class Solution {
public:

    int findMax(vector<int> piles, int n) {
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long findPossiblity(vector<int> piles, long long hourly) {
        long long total = 0;
        for(int i=0; i<piles.size(); i++) {
            total += ceil((double)piles[i]/(double)hourly);
        }        
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = findMax(piles, n);
        int ans = -1;
        while(low<=high) {
            int mid = (low+high)/2;
            long long hours = findPossiblity(piles, mid);
            if(hours<=h) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }        
        return ans;
    }
};