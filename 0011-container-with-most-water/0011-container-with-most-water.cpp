class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0, n = height.size();
        int start = 0, end = n - 1;
        while(start < end) {
            int area = (end - start) * min(height[start], height[end]);
            if(height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
            maxarea = max(maxarea, area);
        } 
        return maxarea;
    }
};