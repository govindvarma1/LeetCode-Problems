class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), prefixSum = 0;
        map<int, int> hashMap;
        for(int i=0; i<n; i++) {
            prefixSum += nums[i];
            int remove = prefixSum%k;
            if((remove == 0 && i > 0) || (hashMap.find(remove) != hashMap.end() && i - hashMap[remove] > 1)) {
                return true;
            }
            if(hashMap.find(remove) == hashMap.end()) {
                hashMap[prefixSum%k] = i;
            }
        }
        return false;
    }
};