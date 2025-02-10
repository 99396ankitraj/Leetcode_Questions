class Solution {
public:
    bool ispossible(int mid , vector<int>&price , int k){
        int count = 1;
        int ele = price[0];

        for(int i = 0 ; i < price.size() ; i++){
            if((price[i]- ele) >= mid){
                count++;
                ele = price[i];
                if(count >= k) return true;
            }
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin() , price.end());
        int low = 0;
        int high = *(max_element(price.begin() , price.end()));
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(ispossible(mid , price , k)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};