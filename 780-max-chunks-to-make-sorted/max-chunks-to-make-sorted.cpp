class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, maxi = 0;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
            
            // Check if the current max equals the index
            if(maxi == i) {
                ans++;
            }
        }
        
        return ans;
    }
};
