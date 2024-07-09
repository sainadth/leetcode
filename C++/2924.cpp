#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        /* 
            TC - O(N)
            SC - O(N)
        */
        vector<int> weak(n, 0);
        for(auto i : edges){
            weak[i[1]]++;
        }
        int miny = *min_element(weak.begin(), weak.end());
        int res = -1;
        int c = 0;
        int ind = 0;
        for(auto i : weak){
            if(i == miny){
                if(c) return -1;
                res = ind;
                c++;
            }
            ind++;
        }
        return res;
    }
};