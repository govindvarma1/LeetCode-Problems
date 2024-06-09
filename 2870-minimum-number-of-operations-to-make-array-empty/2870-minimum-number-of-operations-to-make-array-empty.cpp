class Solution {
public:
    int minOperations(vector<int>& nums) {
        int opr = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            int cnt = 1;
            while(i<n-1 && nums[i] == nums[i+1]) {
                cnt++;
                i++;
            }
            if(cnt<2) {
                return -1;
            } else {
                if(cnt%3 == 0) {
                    opr += cnt/3;
                } else {
                    opr += cnt/3 + 1;
                }
            }
        }   
        return opr;     
    }
};