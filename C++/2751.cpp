#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++) v.push_back({positions[i], healths[i], directions[i] == 'L', i});
        sort(v.begin(), v.end());

        stack<vector<int>> st;
        for(auto i : v){
            if(st.size() && i[2] && st.top()[2] == 0){
                bool skp = false;
                while(st.top()[2] == 0){
                    if(i[1] > st.top()[1]){
                        i[1]--;
                        st.pop();
                    }else if(i[1] == st.top()[1]){
                        skp = true;
                        st.pop();
                        break;
                    }else{
                        skp = true;
                        st.top()[1]--;
                        break;
                    }
                    if(st.size() == 0) break;
                }
                if(!skp) st.push(i);
            }else st.push(i);
        }

        vector<pair<int, int>> rem;
        while(st.size()){
            if(st.top()[1] > 0) rem.push_back({st.top()[3], st.top()[1]});
            st.pop();
        }
        sort(rem.begin(), rem.end());
        vector<int> res(rem.size());
        int j = 0;
        for(auto i : rem) res[j++] = i.second;
        return res;
    }
};