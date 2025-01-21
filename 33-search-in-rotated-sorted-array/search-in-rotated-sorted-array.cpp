class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0 ;
        int high = arr.size()-1;

        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target) return mid;
            else if(arr[low] <= arr[mid])
                (arr[mid] > target  && arr[low] <= target) ? high = mid-1 : low = mid+1;
            else
                 (arr[mid] < target && target <= arr[high]) ? low = mid+1 : high = mid-1;

        }
        return -1;
    }
};