class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        priority_queue<int> pq(nums.begin(), nums.end());
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        int s3 = pq.top();
        pq.pop();

        if (s2 + s3 > s1)
            return s1 + s2 + s3;

        while (!pq.empty()) {
            s1 = s2;
            s2 = s3;
            s3 = pq.top();
            pq.pop();

            if (s2 + s3 > s1)
                return s1 + s2 + s3;
        }

        return 0;
    }
};