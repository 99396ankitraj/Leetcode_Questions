class Solution {
public:
 Solution(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin() , nums.end());
        long long ans = 0;
        while(k){
            int maxi = pq.top();
            pq.pop();
            ans += maxi;
            maxi = ceil(maxi / 3.0);
            pq.push(maxi);
            k--;
        }
        return ans;
    }
};