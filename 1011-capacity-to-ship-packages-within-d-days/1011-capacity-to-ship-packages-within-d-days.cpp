class Solution {
public:

    pair<int, int> sum(vector<int>& weights, int n) {
        int total = 0, maxi = 0;
        for(int i=0; i<n; i++) {
            maxi = max(maxi, weights[i]);
            total += weights[i];
        }
        return {maxi, total};
    }

    int findDays(vector<int> weights, int cap, int n) {
        int days = 1;
        int onBoard = 0;
        for(int i=0; i<n; i++) {
            onBoard += weights[i];
            if(onBoard>cap) {
                days++;
                onBoard = weights[i];
            }
        }
        return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), ans = 0;
        pair<int, int> temp = sum(weights, n);
        int low = temp.first, high=temp.second;
        while(low<=high) {
            int mid = (low+high)/2;
            int k = findDays(weights, mid, n);
            if(days>=k) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return ans;        
    }
};