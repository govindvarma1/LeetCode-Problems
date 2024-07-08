class Solution {
public:

    bool checkValidString(string s) {
        int openMin = 0, openMax = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '(') {
                openMin++;
                openMax++;
            } else if(s[i] == ')') {
                openMin--;
                openMax--;
            } else {
                openMin--;
                openMax++;
            }
            if(openMax < 0) {
                return false;
            }
            openMin = max(openMin, 0);
        }
        return openMin == 0;
    }
};