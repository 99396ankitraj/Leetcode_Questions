class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        int n = classes.size();
        priority_queue<pair<double , int>> pr;
        for(int i = 0 ; i < n ; i++){
            double current_pr = (1.0*classes[i][0])/classes[i][1];
            double updated_pr = (1.0*classes[i][0]+1)/(classes[i][1]+1);
            double delta = updated_pr - current_pr;
            pr.push({delta , i});
        }

        // while(!pr.empty()){
        //     cout<<pr.top().first<<"  "<<pr.top().second<<endl;
        //     pr.pop();
        // }

        while(extra--){
            auto front = pr.top();
            pr.pop();
            double val = front.first;
            int ind = front.second;

            classes[ind][0]++;
            classes[ind][1]++;

            double current_pr = (1.0*classes[ind][0])/classes[ind][1];
            double updated_pr = (1.0*classes[ind][0]+1)/(classes[ind][1]+1);
            double delta = updated_pr - current_pr;
            pr.push({delta , ind});
            
        }

        double ans = 0.0;
        for(int i = 0 ; i < n ; i++){
             ans += (1.0*classes[i][0])/classes[i][1];
        }

        return ans/n;
    }
};