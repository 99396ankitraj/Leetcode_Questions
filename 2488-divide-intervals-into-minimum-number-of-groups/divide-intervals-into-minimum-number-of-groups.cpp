class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<int> start;
    vector<int> end;

    for(vector<int>& a : intervals){
        start.push_back(a[0]);
        end.push_back(a[1]);
    }

    sort(start.begin(),start.end());
    sort(end.begin(),end.end());

    int i=0,j=0;
    int maxGroups = 0,groups = 0;
    while(i<n && j<n){
        if(start[i] <= end[j]){
            groups++;
            i++;
        }
        else{
            groups--;
            j++;
        }
        maxGroups = max(maxGroups,groups);
    }
    return maxGroups;
    }
};
