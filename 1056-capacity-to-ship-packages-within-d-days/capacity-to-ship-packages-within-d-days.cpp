class Solution {
public:
    bool parttionpossible(vector<int>& weights, int days , int mid){
        int sum = 0;
        int count = 1;

        for(int i = 0 ; i < weights.size() ; i++){
            if(sum + weights[i] <= mid){
                sum += weights[i];
            }else{
                count++;
                if(count > days || weights[i] > mid) return false;
                sum = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        int low = 1;
        int high = accumulate(weights.begin() , weights.end() , 0);

        while(low <= high){
            int mid = (low+high)/2;
            if(parttionpossible(weights , days , mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};