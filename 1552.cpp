#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int d, vector<int>& position, int m){
        int cur = position[0];
        m--;
        for(int i = 1; i < position.size() && m > 0; i++){
            if(position[i] - cur >= d){
                cur = position[i];
                m--;
            }
        }
        return m == 0;
    }
    int maxDistance(vector<int>& position, int m) {
        /* 
            TC - O(NlogN) [sorting] + O(NlogD) [while loop]
            SC - O(1)
        */
        sort(position.begin(), position.end());     //O(NlogN)
        int l = 1;
        int r = position.back();
        int res = INT_MIN;
        while(l <= r){                              //O(logD)
            int mid = (l + r) >> 1;
            if(isPossible(mid, position, m)){       //O(n)
                res = max(res, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return res;
    }
};