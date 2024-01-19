class Solution {
public:

    //HashMap Approach
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans; int n = nums.size();
        unordered_map<int, int> hashMap;
        for(int i=0; i<n; i++) {
            hashMap[nums[i]]++;
        }
        for(int i =0; i<n; i++) {
            if(hashMap[nums[i]] == 1) {
                if(hashMap.find(nums[i] + 1) == hashMap.end() && hashMap.find(nums[i] - 1) == hashMap.end()) {
                    ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};