class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int evenSum = 0;
        int oddSum = 0;

        for(int i = 0 ; i < n ; i++){
            if(i % 2 == 0)
                evenSum += nums[i];
            else
                oddSum += nums[i];
        }

        int ans = 0;
        int newEvensum = 0;
        int newOddSum = 0;

        for(int i = 0 ; i < n ; i++){
            if(i%2 == 0){
                evenSum -= nums[i];
                if(evenSum + newOddSum == oddSum + newEvensum){
                    ans++;
                }
                newEvensum += nums[i];
            }
            else{
                oddSum -= nums[i];
                if(evenSum + newOddSum == oddSum + newEvensum){
                    ans++;
                }
                newOddSum += nums[i];
            }
        }
        return ans;
    }
};