class Solution {
public:
    bool checkAvilableColor(int ver , vector<int>&color , vector<vector<int>> &mat , int k){
        for(int i = 0 ; i < mat[ver].size() ; i++){
            if( color[mat[ver][i]] == k)return false;
        }
        return true;
    }
    bool solve(int gar , vector<int>&color , vector<vector<int>> &mat){
        if(gar == mat.size()) return true;

        for(int k = 1 ; k <= 4 ; k++){
            if(checkAvilableColor(gar , color , mat , k)){
                color[gar] = k;
                if(solve(gar+1 , color , mat)) return true;
                color[gar] = 0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> mat(n);
        for(auto itr : paths){
           mat[itr[0]-1].push_back(itr[1]-1);
           mat[itr[1]-1].push_back(itr[0]-1);
        }

        vector<int> color(n , 0);
        solve(0 , color , mat);
        
        return color;
    }
};