class Solution {
public:
    static bool cmp(vector<int> &a , vector<int> &b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin() , courses.end() , cmp);
        priority_queue<int>pq;
        int curr_time = 0;

        for(int i = 0 ; i < n ; i++){
            if(curr_time + courses[i][0] <= courses[i][1]){
                curr_time += courses[i][0];
                pq.push(courses[i][0]);
            }else if(!pq.empty() && pq.top() > courses[i][0]){
                curr_time -= pq.top();
                pq.pop();
                curr_time += courses[i][0];
                pq.push(courses[i][0]);
            }
        }


        return pq.size();
    }
};