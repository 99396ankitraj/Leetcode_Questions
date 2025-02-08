class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0 , r = height.size()-1;
        int leftmost = 0 , rightmost = 0 , maxi = INT_MIN;
        while(l < r){
            int len = r-l;
            if(height[l] <= height[r]){
                leftmost = max(leftmost , height[l]);
                maxi = max(maxi , leftmost*len);
                l++;
            }else{
                rightmost = max(rightmost , height[r]);
                maxi = max(maxi , rightmost*len);
                r--;
            }
        }
        return maxi;
    }
};