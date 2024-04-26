class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long long ans = 0, i = 0, sign = 1;
        while(i<n && s[i] == ' ') {
            i++;
        }
        if(i<n && s[i] == '-') {
            sign = -1;
            i++;
        } else if(i<n && s[i] == '+') {
            i++;
        }
        while(i<n) {
            int num = s[i] - '0';
            if(num>=0 && num<=9) {
                ans = ans*10 + num;
                if(sign*ans < INT_MIN) {
                    return INT_MIN;
                } else if(sign*ans > INT_MAX) {
                    return INT_MAX;
                }
                i++;
            } else {
                return sign*ans;
            }
        }
        return sign*ans;
    }
};