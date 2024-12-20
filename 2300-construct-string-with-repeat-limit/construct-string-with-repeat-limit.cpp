class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        //store all letters frequency in the map
        unordered_map<char , int> mp;
        for(auto itr : s){
            mp[itr]++;
        }

        //now we will push all the element in the heap to store element in the sorted order
        priority_queue<pair<char,int>> pq;
        for(auto itr : mp){
            pq.push({itr.first,itr.second});
        }

        //now we will perform our final task creating desired string
        string ans = "";
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int count = curr.second;
            char ch = curr.first;
            while(count){
                if(count > repeatLimit){
                    count -= repeatLimit;
                    ans += string(repeatLimit , ch);
                    if(!pq.empty()){
                        auto front = pq.top();
                        pq.pop();
                        int c = front.first;
                        int i = front.second;
                        ans += c;
                        i--;
                        if(i != 0) pq.push({c , i});
                    }else{
                        break;
                    }
                }else{
                    ans += string(count , ch);
                    count = 0;
                }
            }
        }
        return ans;
    }
};