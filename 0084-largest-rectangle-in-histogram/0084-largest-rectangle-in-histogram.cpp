class Solution {
public:

    vector<int> nextSmall(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        vector<int> arr(n);
        for(int i=n-1; i>=0; i--) {
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }
            arr[i] = st.top();
            st.push(i);
        }
        return arr;
    }

    vector<int> prevSmall(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }
            arr[i] = st.top();
            st.push(i);
        }
        return arr;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmall(heights);
        vector<int> next = nextSmall(heights);
        int maxArea = 0;
        for(int i=0; i<heights.size(); i++) {
            if(next[i] == -1) {
                next[i] = heights.size();
            }
            int newArea = heights[i] * (next[i] - prev[i] - 1);
            maxArea = max(maxArea, newArea);
        }
        return maxArea;
    }
};