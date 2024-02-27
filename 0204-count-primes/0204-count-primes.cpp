class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) {
            return 0;   
        }
        int cnt = 0;
        vector<int> isPrime(n+1, 1);
        isPrime[1] = 0;
        for(int i=2; i<n; i++) {
            if(isPrime[i] == 1) {
                cnt++;
                for(int j = i; j<n; j+=i) {
                    isPrime[j] = 0;
                }
            }
        }
        return cnt;
    }
};