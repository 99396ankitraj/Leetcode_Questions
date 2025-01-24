class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop(); // Remove elements that are out of the current window
            }
            
            pq.push({nums[i], i});
            
            if (i >= k - 1) {
                ans.push_back(pq.top().first); // Collect the max element for the current window
            }
        }
        
        return ans;
    }
};
