class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        stack<int> st;
        for(int i = n-1; i>=0; i--) {
            int ast = asteroids[i];
            if(ast > 0) {
                bool flag = true;
                while(!st.empty() && st.top() < 0 && flag) {
                    if(abs(st.top()) < ast) {
                        st.pop();
                    } else if (abs(st.top()) == ast) {
                        flag = false;
                        st.pop();
                    } else {
                        flag = false;
                    }
                }
                if(flag) {
                    st.push(ast);
                }
                
            } else {
                st.push(ast);
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};