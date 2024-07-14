#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(int i, int j, string& s){
        for(int k = i + 1, l = 1; k <= ((j + i) >> 1); k++, l++)
            swap(s[k], s[j - l]);
    }
    string reverseParentheses(string& s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(i);
            if(s[i] == ')'){
                reverse(st.top(), i, s);
                st.pop();
            }
        }
        string res = "";
        for(auto i : s) if(i != '(' && i != ')') res += i;
        return res;
    }
};