#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end(), greater<>());
        sort(v.begin(), v.end(), greater<>());

        int l = 0, r = 0;
        long long res = 0;
        long long hc = 1;
        long long vc = 1;
        while(l < h.size() && r < v.size()){
            if(h[l] >= v[r]){
                res += h[l] * vc;
                l++;
                hc++;
            }else{
                res += v[r] * hc;
                r++;
                vc++;
            }
        }

        while(l < h.size()){
            res += h[l] * vc;
            l++;
            hc++;
        }
        while(r < v.size()){
            res += v[r] * hc;
            r++;
            vc++;
        }
        return res;
    }
};