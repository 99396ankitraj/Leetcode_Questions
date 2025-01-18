class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0 , n = plants.size();
        int tank = capacity;
        for(int i = 0 ; i < n ; i++){
            if(tank >= plants[i]){
                tank -= plants[i]; 
                ans += 1;
            }else{
                 ans += i;
                 tank = capacity;
                 tank -= plants[i]; 
                 ans += i+1;
            }
        }
        return ans;
    }
};