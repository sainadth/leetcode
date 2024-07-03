#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent;
public:
    DSU(){
        parent.resize(26);
        int j = 0;
        for(auto &i : parent) i = j++;
    }

    int Find(int x){
        if(parent[x] == x) return x;
        else return Find(parent[x]);
    }

    bool Union(int x, int y){
        int x_parent = Find(x);
        int y_parent = Find(y);

        if(x_parent != y_parent){
            if(x_parent <= y_parent) parent[y_parent] = x_parent;
            else parent[x_parent] = y_parent;
            return true;
        }
        return false;
    }
};


class Solution {
    DSU* LSES;
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        /* 
            TC - O(N + M) M - size of baseStr
            SC - O(N)
        */
        LSES = new DSU();
        int n = s1.size();
        for(int i = 0; i < n; i++){
            LSES->Union(s1[i] - 'a', s2[i] - 'a');
        }
        
        for(auto &i : baseStr) i = 'a' + LSES -> Find(i - 'a');
        return baseStr;
    }
};