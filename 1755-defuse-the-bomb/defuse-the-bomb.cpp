class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n , 0);
        for(int i = 0 ; i < n ; i++){
            int sum = 0;
            if(k > 0){
                for(int j = 1 ; j <= k ; j++){
                    sum += code[(j + i)%n];
                }
                ans[i] = sum;
            }
            if(k < 0){
                for(int j = n-1 ; j >= n - abs(k) ; j--){
                    sum += code[(j + i)%n];
                }
                ans[i] = sum;
            }
        }
        return ans;
    }
};