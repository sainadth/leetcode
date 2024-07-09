#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        /* 
            TC - O(N + K)
            SC - O(N)
        */

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        
        
        int n = c.size();
        
        vector<int> v;
        for(int i = n - k + 1; i < n; i++) v.push_back(c[i]);

        for(auto i : c) v.push_back(i);
        
        vector<int> dp(n + k, 0);
        
        int res = 0;
        for(int i = 1; i < v.size(); i++){
            if(v[i] != v[i - 1]) dp[i] = 1 + dp[i - 1];
            if(i >= k - 1 && dp[i] >= k - 1) res++;
        }
        
        return res;
    }
};