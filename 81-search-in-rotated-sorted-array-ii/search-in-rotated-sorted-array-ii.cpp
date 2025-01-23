class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[low] <= nums[mid]){
                (nums[low] <= target && nums[mid] > target) ? high = mid-1 : low = mid+1;
            }else{
                (nums[mid] < target && nums[high] >= target) ? low = mid+1 : high = mid-1;
            }
        }
        return false;
    }
};