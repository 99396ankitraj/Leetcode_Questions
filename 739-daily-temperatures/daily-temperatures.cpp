class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
         stack<pair<int,int>>st;
         unordered_map<int,int>mp;
         for(int i = 0 ; i < temp.size() ; i++){
            while(!st.empty() && st.top().first < temp[i]){
                mp[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temp[i] , i});
         }

         vector<int>ans(temp.size(), 0);

         for(auto itr : mp){
            ans[itr.first] = itr.second;
         }
       return ans;
    }
};