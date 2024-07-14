#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> st;
        for(auto i : formula){
            if(i >= 'A' && i <= 'Z'){
                st.push({string(1, i), 0});
            }else if(i >= 'a' && i <= 'z'){
                pair<string, int> t = st.top();
                t.first += i;
                st.pop();
                st.push(t);
            }else if(i >= '0' && i <= '9'){
                pair<string, int> t = st.top();
                t.second = t.second * 10 + (i - '0');
                st.pop();
                st.push(t);
            }else st.push({string(1, i), 0});
        }

        vector<pair<string, int>> res(st.size());
        int i = st.size() - 1;
        while(st.size()){
            if(st.top().second == 0) st.top().second++;
            res[i--] = st.top();
            st.pop();
        }

        for(auto i : res){
            if(i.first == ")"){
                stack<pair<string, int>> temp;
                while(st.size() && st.top().first != "("){
                    pair<string, int> p = st.top();
                    p.second *= i.second;
                    temp.push(p);
                    st.pop();
                }
                st.pop();
                while(temp.size()){
                    st.push(temp.top());
                    temp.pop();
                }
            }
            else st.push(i);
        }

        map<string, int> mp;
        while(st.size()){
            mp[st.top().first] += st.top().second;
            st.pop();
        }

        string rS = "";

        for(auto [k, v] : mp){
            stringstream ss;
            ss << k;
            if(v > 1) ss << v;
            rS += ss.str();
        }
        return rS;
    }
};