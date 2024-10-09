#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int minSwaps(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int len = 0;
        for(auto itr : s){
            if(itr == '[') len++;
            else if(len > 0) len--;
        }
        return ceil(len / 2.0);
    }
};