#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        int lev = 0;
        int res = 0;
        
        int r = red, b = blue;
        int i = 1;
        while(r >= 0 && b >= 0){
            if(i & 1){
                if(b >= i) b -= i;
                else break;
            }else{
                if(r >= i) r -= i;
                else break;
            }
            i++;
        }
        
        res = max(res,  i - 1);
        
        r = red, b = blue;
        i = 1;
        while(r >= 0 && b >= 0){
            if(i & 1){
                if(r >= i) r -= i;
                else break;
            }else{
                if(b >= i) b -= i;
                else break;
            }
            i++;
        }
        res = max(res, i - 1);
        return res;
    }
};