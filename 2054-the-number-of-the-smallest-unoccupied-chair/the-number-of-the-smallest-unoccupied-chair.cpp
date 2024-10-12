class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int target = times[targetFriend][0];
        sort(times.begin() ,times.end());
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        set<int> st;
        int chair = 0;

        for(auto itr : times){
            int arival = itr[0];
            int departure = itr[1];

            while(!pq.empty() && arival >= pq.top()[0]){
                 st.insert(pq.top()[1]);
                 pq.pop();
            }

            if(arival == target) return !st.empty() ? *st.begin() : chair;
            

            if(!st.empty()){
                pq.push({departure , *st.begin()});
                st.erase(st.begin());
            }
            else{
                pq.push({departure , chair++});
            }

        }
        return 0;
    }
};