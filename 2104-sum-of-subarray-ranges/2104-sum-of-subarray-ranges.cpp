class Solution {
public:
    int MOD = 1e9 + 7;

    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty()) {
                if(arr[st.top()] > arr[i]) {
                    st.pop();
                } else {
                    break;
                }
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> ans(n, n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty()) {
                if(arr[st.top()] >= arr[i]) {
                    st.pop();
                } else {
                    break;
                }
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNBL(vector<int>& arr, int n) {
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty()) {
                if(arr[st.top()] < arr[i]) {
                    st.pop();
                } else {
                    break;
                }
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNBR(vector<int>& arr, int n) {
        vector<int> ans(n, n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty()) {
                if(arr[st.top()] <= arr[i]) {
                    st.pop();
                } else {
                    break;
                }
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    long long sumSubArrayMin(vector<int>& arr) {
        long long n = arr.size(), ans = 0;
        vector<int> left = getNSL(arr, n), right = getNSR(arr, n);
        for(int i=0; i<n; i++) {
            int leftCnt = i - left[i];
            int rightCnt = right[i] - i;
            ans = (ans + (1LL * arr[i] * leftCnt * rightCnt));
        }
        return ans;
    }

    long long sumSubArrayMax(vector<int>& arr) {
        long long n = arr.size(), ans = 0;
        vector<int> left = getNBL(arr, n), right = getNBR(arr, n);
        for(int i=0; i<n; i++) {
            int leftCnt = i - left[i];
            int rightCnt = right[i] - i;
            ans = (ans + (1LL * arr[i] * leftCnt * rightCnt));
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubArrayMax(nums) - sumSubArrayMin(nums);        
    }
};