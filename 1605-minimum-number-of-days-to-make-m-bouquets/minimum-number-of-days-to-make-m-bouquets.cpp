class Solution {
public:
    bool ispartition(vector<int>&bloom , int m , int k , int mid){
        int count = 0;
        int i = 0;
        int counter = k;
        int n = bloom.size();

        while(i < n){
           bloom[i] <= mid ? counter-- : counter = k;
            
           if(!counter){
              count++;
              counter = k;
           }

           i++;
        }

        return count >= m;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        int ans = -1;
        if(static_cast<long long>(m) * k > n) return -1;


        int low = 1;
        int high = *(max_element(bloom.begin(),bloom.end()));

        while(low <= high){
            int mid = (low+high)/2;
            if(ispartition(bloom , m , k , mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};