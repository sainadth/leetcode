#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        int c = 0;
        for(auto i : arr){
            if(i & 1){
                c++;
                if(c == 3) return true;
            }
            else c = 0;
        }
        return false;
    }
};