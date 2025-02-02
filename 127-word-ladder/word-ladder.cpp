class Solution {
public:
    int ladderLength(string &b, string e, vector<string>& w) {
        int n = w.size();
        int m = w[0].length();
        int ind = -1 , ind2 = -1;

        map<string , int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[w[i]] = i;
        }

        //check if end word is not present in the map
        if(mp.find(e) == mp.end()) return 0;
        //check if begning word is present in the map or not
        bool flag = false;
        if(mp.find(b) == mp.end()){
            mp[b] = n;
            flag = true;
        } 

        //create adj list
        vector<vector<int>> adj(flag ? n + 1 : n);
        
        while(!mp.empty()){
            auto top_ele = mp.begin();
            string str1 = top_ele->first;
            int num1 = top_ele->second;
            if(str1 == e) ind = num1;
            if(str1 == b) ind2 = num1;

            mp.erase(mp.begin());
            for(auto itr : mp){
                string str2 = itr.first;
                int num2 = itr.second;
                int i = 0;
                int count = 0;
                while(i < m){
                    if(str1[i] != str2[i]) count++;
                    i++;
                }

                if(count == 1){
                    adj[num1].push_back(num2);
                    adj[num2].push_back(num1);
                } 
            }
        }

        //now we will perform final task
        queue<int>q;
        vector<int>dist;
        flag ? dist = vector<int>(n+1 , INT_MAX) : dist = vector<int>(n , INT_MAX);

        if(flag){
            q.push(n);
            dist[n] = 0;
        }else{
            q.push(ind2);
            dist[ind2] = 0;
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();

            if(dist[top] == INT_MAX) continue;

            for(auto itr : adj[top]){
                if(dist[top] + 1 < dist[itr]){
                    dist[itr] = dist[top] + 1;
                    q.push(itr);
                }
            }

        }
        
        return dist[ind] == INT_MAX ? 0 : dist[ind]+1;
    }
};