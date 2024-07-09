#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        /*
            TC - O(N)
            SC - O(1) 
        */
        string res = "";
        for(int i = 0; i < s.size(); i++) res += s[(i + k)%s.size()];
        return res;
    }
};