class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<long long> st;
        int n = nums.size();
        for(int i=n-1; i>=0; i--) {
            st.push(nums[i]);
        }
        vector<int> arr(n , -1);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty()) {
                if(st.top() <= nums[i]) {
                    st.pop();
                } else {
                    break;
                }
            }
            if(!st.empty()) {
                arr[i] = st.top();
            }
            st.push(nums[i]);
        }
        return arr;
    }
};