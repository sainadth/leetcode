#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        int k = (n - 1) * 2;
        time %= k;
        int i = 1;
        while(time--){
            i++;
            if(i == n) break;
        }

        while(time > 0){
            i--;
            time--;
        }
        return i;
    }
};