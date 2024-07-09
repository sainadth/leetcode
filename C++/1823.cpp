#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        /* 
            TC - O(N * K)
            SC - O(N)
        */
        queue<int> q;
        for(int i = 1; i <= n; i++) q.push(i);
        k--;
        while(q.size() > 1){
            int t = k;
            while(t--){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};