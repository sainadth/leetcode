#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        /* 
            TC - O(M * N)
            SC - O(M * N)
        */
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>> xyCount(m, vector<pair<int, int>>(n, {0, 0}));
        
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'X'){
                    xyCount[i][j].first++;
                }else if(grid[i][j] == 'Y'){
                    xyCount[i][j].second++;
                }
                if(i > 0){
                    xyCount[i][j].first += xyCount[i - 1][j].first - ((j > 0) ? xyCount[i - 1][j - 1].first: 0);
                    xyCount[i][j].second += xyCount[i - 1][j].second - ((j > 0) ? xyCount[i - 1][j - 1].second: 0);;
                }
                if(j > 0){
                    xyCount[i][j].first += xyCount[i][j - 1].first;
                    xyCount[i][j].second += xyCount[i][j - 1].second;
                }
                if(xyCount[i][j].first == xyCount[i][j].second && xyCount[i][j].first > 0) res++;
            }
        }
        return res;
    }
};