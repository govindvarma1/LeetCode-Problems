class Solution {
public:

    bool solve(long long n,  int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        for(int i=0; i<composition.size(); i++) {
            long long expense = 0;
            for(int j=0; j<composition[i].size(); j++) {
                long long temp_stock = n * composition[i][j];
                if(temp_stock > stock[j]) {
                    expense += (temp_stock-stock[j]) * cost[j];
                }
            }
            if(expense <= budget) {
                return true;
            }
        }
        return false;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long low = 0, high = 1e9;
        long long ans = 0;
        while(low <= high) {
            long long mid = (low+high)/2;
            if(solve(mid, budget, composition, stock, cost) == true) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }  
        return ans;
    }
};