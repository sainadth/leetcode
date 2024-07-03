#include <bits/stdc++.h>
using namespace std;

#define BEGIN(v) v.begin()
#define END(v) v.end()
#define RANGE(v) BEGIN(v), END(v)

class Solution {
public:
    int minDifference(vector<int>& nums) {
        /*
            TC - O(NlogN)
            SC - O(1) 
        */
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(RANGE(nums));
        int n = nums.size();
        if(nums.size() <= 4) return 0;
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};