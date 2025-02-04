class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int max_index = -1 , min_index = -1 , maxi = INT_MIN , mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(maxi < nums[i]){
                maxi =  nums[i];
                max_index = i;
            }
            if(mini > nums[i]){
                mini = nums[i];
                min_index = i;
            }
        }

        //now we will perform the final task
        int num1 = max(max_index , min_index) + 1;
        int num2 = n - min(max_index , min_index);
        int num3 = (min(max_index , min_index)+1) + (n-max(max_index , min_index));
       
        return min(num1 , min(num2 , num3));
    }
};