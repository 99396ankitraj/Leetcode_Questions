class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0 , r = height.size()-1;
        int leftmost = 0 , rightmost = 0 , total = 0;
        while(l < r){
            if(height[l] <= height[r]){
                leftmost = max(leftmost , height[l]);
                total += leftmost-height[l];
                l++;
            }else{
                rightmost = max(rightmost , height[r]);
                total += rightmost-height[r];
                r--;
            }
        }
        return total;
    }
};