class Solution {
public:
    long long minEnd(int n, int x) {
        int count = 1 ;
        long long num = x;
        while(count != n){
            long long  newNum = num + 1;
            // cout<<newNum<<" ";
            if(( num & newNum) != x){
                newNum = x | newNum;
            }
            num = newNum;
            count++;
        }
        return num;
    }
};