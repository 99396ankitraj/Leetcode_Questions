class Solution {
public:
    int findmaxindex(vector<vector<int>>& mat , int col , int n){
        int maxi = INT_MIN;
        int index = -1;
        for(int i = 0 ; i < n ; i++){
            if(maxi < mat[i][col]){
                maxi = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int>ans;
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;

        while(low <= high){
            int mid_col = (low+high)/2;
            int row = findmaxindex(mat , mid_col , n);

            int left = mid_col == 0 ? -1 : mat[row][mid_col-1];
            int right = mid_col == m-1 ? -1 : mat[row][mid_col+1];

            if(mat[row][mid_col] > left && mat[row][mid_col] > right) {
                ans.push_back(row);
                ans.push_back(mid_col);
                return ans;
            }
            else if(left > mat[row][mid_col]) high = mid_col-1;
            else low = mid_col+1;
        }
        return {-1 , -1};
    }
};