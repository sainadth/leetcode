#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        /* 
            TC - O(E) + O(NlogN) //E = no. of edges
            SC - O(N)
        */
        long long res = 0;
        vector<int> degree(n, 0);

        for(auto i : roads)
            degree[i[0]]++, degree[i[1]]++;

        sort(degree.begin(), degree.end());

        int k = 1;
        for(auto i : degree){
            res += 1ll * k * i;
            k++;
        }
        return res;
    }
};