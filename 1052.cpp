#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        /*
            TC - O(N)
            SC - O(N) 
        */

        int n = customers.size();
        vector<int> pref(n + 1, 0), satisfy(n + 1, 0);

        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i] + customers[i];
            satisfy[i + 1] = satisfy[i];
            if(!grumpy[i]) satisfy[i + 1] += customers[i];
        }

        int res = INT_MIN;
        for(int i = 0; i < n; i++){
            res = max(res, satisfy[n] - satisfy[i + 1] + pref[i + 1] - pref[max(0, i + 1 - minutes)] + satisfy[max(0, i + 1 - minutes)]);
        }
        return res;
    }
};