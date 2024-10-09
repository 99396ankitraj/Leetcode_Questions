class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int c = 1;
        for(auto i:st)mp[i]=c++;
        for(int i=0;i<arr.size();i++)arr[i] = mp[arr[i]];
        return arr;
    }
};