class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1; i<n; i++) {
            string temp = "";
            int ptr = 0, m = ans.size();;
            while(ptr < m) {
                int count = 0;
                char ch = ans[ptr];
                while(ptr<m && ans[ptr] == ch) {
                    count++;
                    ptr++;
                }
                temp += count + '0';
                temp += ch;
            }
            ans = temp;
        }
        return ans;
    }
};