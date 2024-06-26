#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        /* 
            TC - O(N)
            SC - O(N)
        */
        int n = nums.size();
        unordered_map<int, int> mp;
        int res = 0;
        int s = 0;
        mp[0]++;
        for(int i = 0; i < n; i++){
            s += nums[i] & 1;
            mp[s]++;
            if(mp.count(s - k)) res += mp[s - k];
        }

        return res;
    }
};