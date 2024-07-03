#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        int res = 0;
        int prev = 1;
        int cur = 0;
        for(auto i : nums){
            if((i + prev) & 1){
                prev = i;
                cur++;
            }
        }
        res = max(res, cur);
        
        prev = 0;
        cur = 0;
        for(auto i : nums){
            if((i + prev) & 1){
                prev = i;
                cur++;
            }
        }
        res = max(res, cur);
        
        int e = 0;
        int o = 0;
        for(auto i : nums){
            if(i & 1) o++;
            else e ++;
        }
        
        res = max({res, o, e});
        return res;
        
    }
};