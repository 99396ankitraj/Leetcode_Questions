class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string , vector<string>>mp;

        for(auto itr : strs){
            string s = itr;
            sort(s.begin() , s.end());
            mp[s].push_back(itr);
        }

        for(auto itr : mp){
            ans.push_back(mp[itr.first]);
        }
        return ans;
    }
};