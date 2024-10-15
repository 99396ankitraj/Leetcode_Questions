class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() ,cmp);
        int currentEnd = intervals[0][1] , n = intervals.size();
        int ans = 0;

        for(int i = 1 ; i < n ; i++){
            if(currentEnd <= intervals[i][0]){
                currentEnd = intervals[i][1];
            }
            else ans++;
        }
        
        return ans;
    }
};