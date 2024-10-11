struct Comparator{
    bool operator()(const vector<int>&v1, const vector<int>&v2){
        if(v1[1]==v2[1]){
            return v1[0] > v2[0];
        }
        return v1[1]>v2[1];
    }
};
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int idx) {
        ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
        priority_queue<vector<int>, vector<vector<int>>, Comparator>pq;
        set<int> available;
        int st = times[idx][0];
        int n = times.size();
        int cc = -1;
        sort(times.begin(),times.end());
        for(int i=0;i<n;i++){
            while(pq.size() && pq.top()[1]<=times[i][0]){
                available.insert(pq.top()[2]);
                pq.pop();
            }
            if(available.size()){
                int avb = *available.begin();
                if(st==times[i][0])return avb;
                pq.push({times[i][0],times[i][1],*available.begin()});
                available.erase(avb);
            }else{
                cc++;
                if(st==times[i][0])return cc;
                pq.push({times[i][0],times[i][1],cc});
            }
        }
        return -1;
    }

};