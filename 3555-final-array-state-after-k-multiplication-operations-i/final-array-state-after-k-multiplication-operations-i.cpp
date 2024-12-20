class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int len = nums.size();
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i = 0 ; i < len ; i++){
            pq.push({nums[i] , i});
        }

        while(k){
            auto front = pq.top();
            pq.pop();
            nums[front.second] = nums[front.second]*mul;
            pq.push({ nums[front.second] , front.second});
            k--;
        }
        return nums;
    }
};