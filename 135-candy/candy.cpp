class Solution {
public:
    int candy(vector<int>& ra) {
         int n = ra.size();
         int ans = 0;
         vector<int>store(n , 1);
         if(n == 1) return 1;
         for(int i = 0 ; i < n ; i++){
            if(i == 0){ 
                if(ra[i] > ra[i+1]){
                    ans += 2 ;
                    store[i] = 2;
                }else{
                    ans+=1;
                }
            }
            else if(i == n-1){
                if(ra[i] > ra[i-1]){
                    ans += (store[i-1]+1);
                    store[i] = store[i-1] + 1;
                }else{
                    ans+=1;
                }
            }else{
                if(ra[i] > ra[i-1]){
                    ans += (store[i-1]+1);
                    store[i] = store[i-1] + 1;
                }else if(ra[i] > ra[i+1]){
                     ans += 2;
                     store[i] = 2;

                     if(store[i] >= store[i-1] && ra[i] < ra[i-1]){
                        int j = i;
                        while(j > 0 && store[j] >= store[j-1] && ra[j] < ra[j-1]){
                            ans-=store[j-1];
                            store[j-1] = store[j]+1;
                            ans += store[j-1];
                            j--;
                        }
                     }

                }else{
                    ans += 1;
                }
            }   
        }
        return ans;
    }
};