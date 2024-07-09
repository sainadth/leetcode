#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumPoints(vector<int>& e, int c) {
        /* 
            TC - O(NlogN) + O(N) = O(NlogN)
            SC - O(1)
        */
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(e.begin(), e.end());
        long long p = 0;
        while(e.size()){
            int k = c/e[0];
            p += k;
            c -= k * e[0];
            if(p) c += e.back();
            e.pop_back();
        }
        return p;
    }
};