#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        /* 
            TC - O(N)
            SC - O(N)
        */
        stack<string> s;
        for(auto i : logs){
            if(i == "../"){if(s.size()) s.pop();}
            else if(i == "./") continue;
            else s.push(i);
        }
        return s.size();
    }
};