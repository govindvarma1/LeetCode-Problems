class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), prefixSum = 0, cnt = 0;
        map<int, int> hashMap;
        hashMap[0] = 1;
        for(int i=0; i<n; i++) {
            prefixSum += nums[i];
            int remove = prefixSum - k;
            cnt += hashMap[remove];
            hashMap[prefixSum]++;
        }
        return cnt;
    }
};