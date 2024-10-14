class Solution {
public:
    int thirdMax(vector<int>& nums) {

        int n = nums.size();

        if(n==1){
            return nums[0];
        }

        if(n==2){
            return nums[0]> nums[1]? nums[0]: nums[1];
        }

        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for(int num : nums){


            if (num == first || num == second || num == third) {
                continue; 
            }

            if(num > first ){
                third = second;
                second = first;
                first = num;
              
            }
            else if(num> second){

                third = second;
                second = num;

            }
            else if(num > third){
                third = num;
            }
        }

        return third==LONG_MIN ? first : third;
        
    }
};