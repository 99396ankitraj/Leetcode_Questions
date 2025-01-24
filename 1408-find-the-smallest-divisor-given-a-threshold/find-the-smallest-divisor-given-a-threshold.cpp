class Solution {
public:
    bool ispossible(vector<int>&nums , int threshold , int mid){
        int count = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            count += ceil((double)nums[i]/mid);
            if(count > threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        int low = 1;
        int high = *(max_element(nums.begin(),nums.end()));

        while(low <= high){
            int mid = (low+high)/2;
            if(ispossible(nums,threshold,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};