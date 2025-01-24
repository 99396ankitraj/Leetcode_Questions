class Solution {
public:
    int ispartition(vector<int>&piles , int h , int mid){
        int count = 0;

        for(int i = 0 ; i < piles.size() ; i++){
            count += (piles[i] + mid - 1) / mid;
            if(count > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        long long high = *(max_element(piles.begin() , piles.end()));
        int ans = -1;

        while(low <= high){
            int mid = (low+high)/2;
            if(ispartition(piles , h , mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        }

        return ans;
    }
};