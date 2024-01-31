class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        s.push(-1);
        int n = temperatures.size();
        vector<int> nextGreaterValue(n);    
        for(int i=n-1; i>=0; i--) {
            while(s.top()!=-1 && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            if(s.top() == -1) {
                nextGreaterValue[i] = 0;
            } else {
                nextGreaterValue[i] = s.top() - i;
            }
            s.push(i);
        }    
        return nextGreaterValue;
    }
};