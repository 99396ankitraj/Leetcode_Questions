class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        // Min-heap to store {value, array_index, element_index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> ans;
        int maxi = INT_MIN;

        // Push the first element of each array into the min-heap
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }

        while (true) {
            if (ans.empty() || (ans[1] - ans[0]) > (maxi - pq.top()[0])) {
                ans = {pq.top()[0], maxi};
            }
            
            auto top = pq.top();
            int ele = top[0];
            int arr_number = top[1];
            int itr = top[2];
            pq.pop();
            
            // Check if there's a next element in the same array
            if (itr + 1 == nums[arr_number].size()) {
                break;
            }
            
            pq.push({nums[arr_number][itr + 1], arr_number, itr + 1});
            maxi = max(maxi, nums[arr_number][itr + 1]);
        }

        return ans;
    }
};
