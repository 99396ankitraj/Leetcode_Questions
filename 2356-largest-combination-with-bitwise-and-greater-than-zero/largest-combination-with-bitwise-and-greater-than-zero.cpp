class Solution {
public:
    int largestCombination(vector<int>& can) {
        int n = can.size() , maxi = INT_MIN;
        for(int i = 0 ; i < 24; i++){
            int count = 0 ;
            for(int j = 0 ; j < n ; j++){
                if((can[j] & (1 << i) )!= 0) count++;
            }
            maxi = max(maxi , count);
        }
        return maxi;
    }
};
auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();
