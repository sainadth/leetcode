#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        /* 
            TC - O(N * N)
            SC - O(N)
        */
        map<string, int> mp;
        int n = s.length();
        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = i; j < n; j++){
                if(temp.size())
                    if(temp.back() != s[j]) break;
                temp += s[j];
                mp[temp]++;
            }
        }
        int res = -1;
        for(auto [k, v] : mp){
            if(v > 2){
                res = max(res, (int)k.length());
                cout << k << endl;
            }
        }
        return res;
    }
};