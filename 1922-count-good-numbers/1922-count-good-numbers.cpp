class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long findPow(long long x, long long n) {
        long long ans = 1;
        while(n>0) {
            if(n%2 == 1) {
                ans = (ans * x)%MOD;
            }
            x = (x * x)%MOD;
            n = n/2;
        }
        return ans%MOD;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        return (findPow(5, even) * findPow(4, odd))%MOD;
    }
};