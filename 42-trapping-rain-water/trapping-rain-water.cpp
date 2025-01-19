class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //firstly we will create max prefix array
        vector<int>prefix(height);
        prefix[0] = height[0];
        for(int i = 1 ; i < n ; i++){
            if(prefix[i-1] > height[i]){
                prefix[i] = prefix[i-1];
            }
        }

        //now we will create suffix array
        vector<int>suffix(height);
        suffix[n-1] = height[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            if(suffix[i+1] > height[i]){
                suffix[i] = suffix[i+1];
            }
        }

        //now we will perform final step to get final answer
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += min(prefix[i] , suffix[i]) - height[i];
        }

        for(auto itr : prefix){
            cout<<itr<<" ";
        }
        cout<<endl;
        for(auto itr : suffix){
            cout<<itr<<" ";
        }
        
            return ans;
    }
};