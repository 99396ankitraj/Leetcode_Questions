class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char>s1(exp.begin(),exp.end());
        stack<char>s2;
        char flag = ' ';
        while(!s1.empty()){
            while(!s1.empty() && ( s1.top() == ')' || s1.top() == '(' || s1.top() == 't' || s1.top() == 'f' || s1.top() == ',')){
                if(s1.top() != ',')s2.push(s1.top());
                s1.pop();
            }
            int fc = 0 , tc = 0;
            while(!s2.empty() && s2.top() != ')'){
                if(s2.top() == 'f') fc++;
                if(s2.top() == 't') tc++;
                s2.pop();
            }
            s2.pop();
            if(s1.top() == '&'){
                fc ? flag = 'f' : flag = 't';
                flag=='f' ? s2.push('f') : s2.push('t');
            }else if(s1.top() == '|'){
                tc ? flag = 't' : flag = 'f';
                if(tc) flag = true;
                flag=='f' ? s2.push('f') : s2.push('t');
            }else if(s1.top() == '!'){
                tc ? flag = 'f' : flag = 't';
                flag=='f' ? s2.push('f') : s2.push('t');
            }
            s1.pop();
        }
        if(s2.top() == 't') return true;
        return false;
    }
};