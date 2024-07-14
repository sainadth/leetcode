#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        for(int i = 1; i < s.size(); i++){
            int a = (s[i] - '0') & 1;
            int b = (s[i - 1] - '0') & 1;
            if(a == b && s[i] < s[i - 1]){
                swap(s[i], s[i - 1]);
                return s;
            }
        }
        return s;
    }
};