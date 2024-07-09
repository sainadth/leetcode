#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        int n = customers.size();
        double res = 0;
        int prev = 0;
        for(auto i : customers){
            if(i[0] < prev){
                res += prev + i[1] - i[0];
                prev = i[1] + prev;
            }
            else{
                res += i[1];
                prev = i[1] + i[0];
            }
        }
        return res/n;
    }
};