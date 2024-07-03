#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& m, vector<int>& n) {
        /* 
            TC - O(N)
            SC - O(N)
        */
        map<int, int> mf, nf;
        for(auto i : m){
            mf[i]++;
        }

        for(auto i : n){
            nf[i]++;
        }

        vector<int> res;
        for(auto [k, v] : mf){
            int c = min(v, nf[k]);
            while(c--){
                res.push_back(k);
            }
        }
        return res;
    }
};