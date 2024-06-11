class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> arr(n2, 0);
        stack<int> st;
        for(int i=n2-1; i>=0; i--) {
            if(st.empty()) {
                arr[i] = -1;
            } else {
                while(!st.empty()) {
                    if(nums2[i] >= nums2[st.top()]) {
                        st.pop();
                    } else {
                        break;
                    }
                }
                if(st.empty()) {
                    arr[i] = -1;
                } else {
                    arr[i] = st.top();
                }
            }
            st.push(i);
        }
        vector<int> ans(n1, -1);
        for(int i=0; i<n1; i++) {
            for(int j=0; j<n2; j++) {
                if(nums1[i] == nums2[j]) {
                    if(arr[j] != -1) {
                        ans[i] = nums2[arr[j]];
                    }
                    break;
                }
            }
        }
        return ans;
    }
};