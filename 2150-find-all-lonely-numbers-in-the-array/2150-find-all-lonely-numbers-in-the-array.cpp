class Solution {
public:

    int binarySearch(vector<int>& nums, int target) {
        int start = 0, end = nums.size() -1, mid;
        while(start <= end) {
            mid = (start + end) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    bool isRepetative(vector<int>& nums, int target) {
        int ind = binarySearch(nums, target), n =nums.size();
        if(ind > 0 && nums[ind-1] == nums[ind]) {
            return true;
        } 
        if(ind < n-1 && nums[ind+1] == nums[ind]) {
            return true;
        }
        return false;
    }

    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(!isRepetative(nums, nums[i]) && (i==0 || nums[i-1] != nums [i] -1) && (i==n-1 || nums[i+1] != nums[i]+1)) {
                ans.push_back(nums[i]);
            }
        }               
        return ans;
    }
};