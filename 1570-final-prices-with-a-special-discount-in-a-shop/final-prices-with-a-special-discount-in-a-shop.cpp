class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n , -1);
        stack<int> st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                arr[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        for(int i = 0 ; i < n ; i++){
           if(arr[i] != -1){
              nums[i] -= arr[i];
           }
        }
        return nums;
    }
};