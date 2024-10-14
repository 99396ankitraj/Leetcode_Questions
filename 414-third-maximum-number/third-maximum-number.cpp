class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int , greater<int>> pq(nums.begin() ,nums.end());
        if(pq.size() < 3) return *pq.begin();
        pq.erase(pq.begin());
        pq.erase(pq.begin());
        
        return *pq.begin();
    }
};