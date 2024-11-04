class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while(low < high) {
            if(!isalnum(s[low])) {
                low++;
                continue;
            }
            if(!isalnum(s[high])) {
                high--;
                continue;
            }
            if(tolower(s[low]) != tolower(s[high])) {
                return false;
            }
            high--;
            low++;
        }
        return true;
    }
};