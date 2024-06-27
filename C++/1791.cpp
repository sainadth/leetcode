#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int res = 0;
        int c = 0;
        for(auto i : edges){
            if(res == i[0]){
                c++;
            }else{
                c--;
                if(c <= 0){
                    res = i[0];
                    c = 1;
                }
            }

            if(res == i[1]){
                c++;
            }else{
                c--;
                if(c <= 0){
                    res = i[1];
                    c = 1;
                }
            }
        }
        return res;
    }
};