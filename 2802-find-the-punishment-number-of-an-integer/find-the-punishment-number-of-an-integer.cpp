class Solution {
public:
    bool solve(int ind , int num , string str ,int sum){
        if(ind == str.length()){
            if(sum == num) return true;
            return false;
        }

        for(int i = ind ; i < str.length() ; i++){
            int a =  stoi(str.substr(ind , i-ind+1));
            sum += a;
            if(solve(i+1 , num , str , sum)) return true;
            sum -= a;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            int num = i*i;
            if(solve(0 , i , to_string(num) , 0)){
                ans += num;
            }
        }
        return ans;
    }
};