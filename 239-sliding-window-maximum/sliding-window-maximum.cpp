class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        int i = 0, j = 0;
        
        while (j < k) {
            // Maintain the order in the priority queue, so we only store valid elements for the window.
            pq.push({nums[j], j});
            j++;
        }
        
        vector<int> ans(n - k + 1); // Result vector with the correct size
        
        // Record the maximum element for the first window
        ans[i] = pq.top().first;
        
        // Now, slide the window across the array
        while (j < n) {
            // Remove the element that is out of the window
            while (!pq.empty() && pq.top().second <= i) {
                pq.pop();
            }
            
            // Add the new element to the window
            pq.push({nums[j], j});
            
            // The top element in the priority queue is the max for the current window
            i++;
            ans[i] = pq.top().first;
            j++;
        }

        return ans;
    }
};
