class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int,int> mp;
        set<int> st;
        vector<int> ans(n , -1);

        for(int i = 0 ; i < n ; i++){
            if(rains[i] == 0){
                st.insert(i);
                continue;
            }
            if(mp.count(rains[i])){
                auto it = st.upper_bound( mp[rains[i]]);
                if(it == st.end()){
                    return {};
                }else{
                    ans[*it] = rains[i];
                    mp[rains[i]] = i;
                    st.erase(*it);
                }
            }else{
                mp[rains[i]] = i;
            }
        }

        for(auto itr : st){
            ans[itr] = 1;
        }
        return ans;
    }
};