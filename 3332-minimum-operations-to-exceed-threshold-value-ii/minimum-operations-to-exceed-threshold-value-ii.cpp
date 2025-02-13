class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        priority_queue<long long , vector<long long> , greater<long long>> pq(nums.begin() , nums.end());
        while(!pq.empty() && pq.top() < k){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long num = min(a,b) * 2 + max(a, b);
            pq.push(num);
            count++;
        }
        return count;
    }
};