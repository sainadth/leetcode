#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int n, int e) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        int res = 0;
        while(n){
            if(n < e){
                res += n;
                n = 0;
            }else{
                int k = n/e;
                res += k * e;
                n = n/e + n%e;
            }
        }
        return res;
    }
};