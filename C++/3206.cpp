#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int res = 0;
        for(int i = 1; i < colors.size() - 1; i++){
            if(colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) res++;
        }
        if(colors[0] != colors[1] && colors[0] != colors.back()) res++;
        if(colors[0] != colors.back() && colors[colors.size() - 2] != colors.back()) res++;
        return res;
    }
};