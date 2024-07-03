#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        /* 
            TC - O(N * M)
            SC - O(N + M)
        */
        
        int m = grid.size();
        int n = grid[0].size();

        vector<int> r(m, 0);
        vector<int> c(n, 0);


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) r[i]++, c[j]++;
            }
        }

        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    if(r[i] > 1 || c[j] > 1) res++;
                }
            }
        }
        return res;
    }
};