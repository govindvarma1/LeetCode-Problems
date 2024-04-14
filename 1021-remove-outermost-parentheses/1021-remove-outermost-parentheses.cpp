class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<n; i++) {
            if(s[i] == '(') {
                if(st.size() > 0) {
                    ans += s[i];
                }
                st.push(s[i]);
            } else {
                if(st.size() > 1) {
                    ans += ")";
                }
                st.pop();
            }
        }
        return ans;
    }
};