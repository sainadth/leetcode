#include <bits/stdc++.h>
using namespace std;

class Solution {
    stack<char> st, helper;
public:
    int solve(int i, string& s, int x, int y){
        st = stack<char>();
        char A = 'a', B = 'b';
        if(i) swap(A, B);
        
        int res = 0;
        for(auto i : s){
            if(i == B){
                if(st.size()){
                    if(st.top() == A){
                        st.pop();
                        res += x;
                        continue;
                    }
                }
            }
            st.push(i);
        }

        while(st.size()){
            helper.push(st.top());
            st.pop();
        }

        cout << helper.size();

        while(helper.size()){
            if(helper.top() == A){
                if(st.size()){
                    if(st.top() == B){
                        helper.pop();
                        st.pop();
                        res += y;
                        continue;
                    }
                }
            }
            st.push(helper.top());
            helper.pop();
        }
        return res;
    }

    int maximumGain(string s, int x, int y) {
        int resX = 0, resY = 0;
        resX = solve(0, s, x, y);
        resY = solve(1, s, y, x);
        return max(resX, resY);
    }
};