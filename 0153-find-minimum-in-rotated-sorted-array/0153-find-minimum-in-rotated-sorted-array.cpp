class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(nums[mid]<nums[low] && nums[mid]<nums[high]) {
                high = mid;
            } else if(nums[low]<=nums[mid] && nums[mid]<=nums[high]) {
                return nums[low];
            } else if(nums[low]<=nums[mid] && nums[high]<=nums[low]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return nums[low];
    }
};