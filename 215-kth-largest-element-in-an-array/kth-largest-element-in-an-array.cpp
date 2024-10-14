class Solution {
public:
    int pivotIndex(vector<int>&nums, int l, int r) {
        int p = nums[l];
        int i = l+1;
        int j = r;

        while(i <= j){
            if(nums[i] < p && nums[j] > p)swap(nums[i++] , nums[j--]);
            if(nums[i] >= p) i++;
            if(nums[j] <= p) j--;
        }
        swap(nums[l] ,nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int p = 0, l = 0, r = nums.size()-1;

        while (true) {
            p = pivotIndex(nums , l, r);

            if (p == k - 1)
                break;
            else if (p > k - 1)
                r = p-1;
            else
                l = p+1;
        }
        return nums[p];
    }
};