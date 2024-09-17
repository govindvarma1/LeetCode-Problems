class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans = "";
        int n = path.size(), i = 0;
        while(i<n) {
            while(i<n && path[i] == '/') {
                i++;
            }
            string s = "";
            while(i<n && path[i] != '/') {
                s += path[i];
                i++;
            }
            if(s == "." || s == "") {
                continue;
            } else if(s == "..") {
                 if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(s);
            }
        }
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans == "") {
            return "/";
        }
        return ans;
    }
};