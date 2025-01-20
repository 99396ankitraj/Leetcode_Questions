class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>freq;
        for(auto itr : words) freq[itr]++;
        int len = words[0].length();

        vector<int> ans;
        for(int i = 0 ; i < len ; i++){
            unordered_map<string,int>store;
            int count = 0;
            for(int j = i ; j+len <= s.length() ; j += len){
                string str = s.substr(j , len);

                auto itr = freq.find(str);
                if(itr == freq.end()){
                    store.clear();
                    count = 0;
                    continue;
                }

                store[str]++;
                count++;
                while(store[str] > itr->second){
                    string first = s.substr(j-(count-1)*len , len);
                    store[first]--;
                    count--;
                }

                if(count == words.size()){
                    ans.push_back(j-(count-1)*len);
                }
            }
        }

        return ans;
    }
};