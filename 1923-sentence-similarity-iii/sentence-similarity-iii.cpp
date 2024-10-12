class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) swap(s1 , s2);

        deque<string> dq1 , dq2;

        stringstream ss1(s1);
        string token;
        while(ss1 >> token){
            dq1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token){
            dq2.push_back(token);
        }

        while(!dq2.empty() && dq1.front() == dq2.front()){
            dq1.pop_front();
            dq2.pop_front();
        }

        while(!dq2.empty() && dq1.back() == dq2.back()){
            dq1.pop_back();
            dq2.pop_back();
        }

        return dq2.empty();
    }
};