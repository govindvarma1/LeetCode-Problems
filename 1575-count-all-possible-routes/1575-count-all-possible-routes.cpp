class Solution {
public:

    int mod = 1e9+7;

    int solve(vector<int>& locations,vector<vector<int>>& dp, int curr, int finish, int fuel) {
        if(fuel < 0) {
            return 0;
        }
        if(dp[curr][fuel] != -1) {
            return dp[curr][fuel];
        }
        int ans = 0;
        if(curr == finish) {
            ans++;
        }
        for(int i=0; i<locations.size(); i++) {
            if(curr != i) {
                ans = ans%mod + solve(locations, dp, i, finish, fuel - abs(locations[curr]- locations[i]))%mod;                
            }
        }
        return dp[curr][fuel] = ans%mod;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n+1, vector(fuel+1, -1));
        return solve(locations, dp, start, finish, fuel);      
    }
};