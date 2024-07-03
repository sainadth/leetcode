#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    float resolve(int n, int d){
        if(d == 0) return INT_MAX;
        float res = 1;
        res *= n;
        res /= __gcd(n, d);
        d /= __gcd(n, d);
        res /= d;
        return res;
    }
    int maxPoints(vector<vector<int>>& points) {
        /* 
            TC - O(N * N)
            SC - O(1)
        */
        int res = 0;
        int n = points.size();
        if(n == 1) return 1;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                float m = resolve(points[j][1] - points[i][1], points[j][0] - points[i][0]);
                int cnt = 2;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j) continue;
                    if(m == resolve(points[k][1] - points[i][1], points[k][0] - points[i][0])) cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};i