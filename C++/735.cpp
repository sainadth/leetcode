#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        for(auto i : a){
            if(st.size() && i < 0){
                bool skp = false;
                while(true){
                    if(st.top() < 0) break;
                    if(st.top() < abs(i)) st.pop();
                    else if(st.top() == -i){
                        st.pop(), skp = true;
                        break;
                    }
                    else{
                        skp = true;
                        break;
                    }
                    if(st.size() == 0) break;
                }
                if(!skp) st.push(i);
            }else st.push(i);
        }
        vector<int> res(st.size());
        int j = st.size();
        while(j){
            res[j - 1] = st.top();
            st.pop();
            j--;
        }
        return res;
    }
};