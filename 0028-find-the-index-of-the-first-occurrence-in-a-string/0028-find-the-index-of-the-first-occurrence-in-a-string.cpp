class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for(int i=0; i<haystack.size(); i++) {
            bool flag = true;
            for(int j=0; j<m; j++) {
                if(i + j >= n || haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                return i;
            }
        }   
        return -1;
    }
};