class Solution {
public:

    void nextPermutation(vector<int>& num, int n) {
        int l, k;
        for(l=n-2; l>=0; l--) {
            if(num[l] < num[l+1]) {
                break;
            }
        }
        if(l < 0) {
            reverse(num.begin(), num.end());
        } else {
            k = n-1;
            for(k = n-1; k>l; k--) {
                if(num[k] > num[l]) {
                    break;
                }
            }
            swap(num[l], num[k]);
            reverse(num.begin() + l + 1, num.end());
        }
    }

    string getPermutation(int n, int k) {
        if(n == 1) {
            return "1";
        }
        vector<int> num(n);
        for(int i=0; i<n; i++) {
            num[i] = i+1;
        }
        for(int i=1; i<k; i++) {
            nextPermutation(num, n);
        }
        string ans = "";
        for(int i=0; i<n; i++) {
            char ch = num[i] + '0';
            ans += ch;
        }
        return ans;
    }
};