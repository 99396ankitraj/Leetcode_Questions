class Solution {
public:
    int digit_sum(int num){
        int sum = 0;
        while(num != 0){
            sum += (num%10);
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        pq.push(-1);

        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
           int num = digit_sum(nums[i]);
           if(mp.count(num)){
              int sum = nums[i] + mp[num];
              pq.push(sum);
              if(mp[num] < nums[i]) mp[num] = nums[i];
           }else{
             mp[num] = nums[i];
           }
        }

        return pq.top();
    }
};