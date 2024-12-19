class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n , false);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i = 0 ; i < n ; i++){
            pq.push({nums[i] , i});
        }

        long long ans = 0;
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int i = front.second;

            if(vis[i]){
                continue;
            }

            if(i-1 >= 0 && !vis[i-1]){
                vis[i-1] = true;  
            } 

            if(i+1 < n && !vis[i+1]){
                vis[i+1] = true;  
            }
            if(!vis[i]){ 
                vis[i] = true;
                ans += nums[i];
            }
        }
        return ans;
    }
};