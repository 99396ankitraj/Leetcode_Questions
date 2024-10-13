#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> v;
        for (const auto& itr : nums) {
            for (const auto& it : itr) {
                v.push_back(it);
            }
        }
        sort(v.begin(), v.end());

        vector<int> ans;
        int n = v.size();
        int i = 0, j = 0, len = numeric_limits<int>::max();

        while (i <= j && j < n) {
            if (v[j] - v[i] < len) {
                int x = nums.size();
                for (int k = 0; k < nums.size(); k++) {
                    auto it = lower_bound(nums[k].begin(), nums[k].end(), v[i]);
                    if (it != nums[k].end() && *it <= v[j]) {
                        x--;
                    } else {
                        break;
                    }
                }
                if (x == 0) {
                    if (ans.empty() || ans[1] - ans[0] > v[j] - v[i]) {
                        ans = {v[i], v[j]};
                        len = v[j] - v[i];  
                    }
                    i++;  
                } else {
                    j++;  
                }
            } else {
                i++;
            }
        }
        return ans;
    }
};
