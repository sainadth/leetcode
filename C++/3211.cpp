#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, string& s, vector<string>& res){
        if(n == 0){
            res.push_back(s);
            return;
        }
        if(s.size() && s.back() == '0'){
            s.push_back('1');
            solve(n - 1, s, res);
            s.pop_back();
        }else{
            s.push_back('1');
            solve(n - 1, s, res);
            s.pop_back();
            s.push_back('0');
            solve(n - 1, s, res);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        /*
            TC - O(2^N) ~ O(1 << 18) ~ O(2,62,144) // less than 10^8
            SC - O(1)

            Approach
            1. Using DFS
            2. Substring of length 2 should have atleast one 1
                2.1 That means there should be no 2 adjacent 0s
                    0 1 VALID   - previous character 0 then next character must be 1
                    1 0 VALID   - previous character 1 then next character can be 0
                    1 1 VALID   - previous character 1 then next character can be 1
                    0 0 INVALID
            3. We take a string to store valid string (reference to avoid MLE)
            4. IF string size is 0 or previous character is 1
                4.1 Next character can be either 0 or 1
            5. ELSE next character must be 1
            6. One string length is N add it to res vector
            7. Return res
        */
        vector<string> res;
        string s = "";
        solve(n, s, res);
        return res;
    }
};