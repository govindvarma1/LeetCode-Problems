class Solution {
public:

    int findMax(vector<int>& bloomDay, int n) {
        int maxi = 0;
        for(int i=0; i<n; i++) {
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }

    int findBouquets(vector<int>& bloomDay,int day, int n, int k) {
        int cnt = 0;
        int curr = 0;
        for(int i=0; i<n; i++) {
            if(bloomDay[i]>day) {
                curr = 0;
            } else {
                curr++;
            }
            if(curr==k) {
                curr=0;
                cnt++;
            }
        }
        return cnt;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), ans=-1;
        int low=1, high = findMax(bloomDay, n);
        while(low<=high) {
            int mid = (low+high)/2;
            int bouqs = findBouquets(bloomDay, mid, n, k);
            if(bouqs>=m) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }   
        return ans;    
    }
};