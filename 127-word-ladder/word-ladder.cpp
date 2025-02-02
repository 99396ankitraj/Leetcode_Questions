class Solution {
public:
    int ladderLength(string b, string e, vector<string>& word) {
        int m = word[0].length();
        set<string> st(word.begin() , word.end());
        st.erase(b);
        queue<pair<string , int>> q;
        q.push({b , 1});

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(int i = 0 ; i < m ; i++){
                 string str = top.first;
                 int num = top.second;
                for(int j = 0 ; j < 26 ; j++){
                    str[i] = j + 'a';
                    if(st.find(str) != st.end()){
                        if(str == e) return num+1;
                        st.erase(str);
                        q.push({str , num+1});
                    }
                }
            }

        }

        return 0;
    }
};