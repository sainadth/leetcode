#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n);
        int j = 0;
        for(auto &i : parent) i = j++;
    }

    int Find(int x){
        if(parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y){
        int x_parent = Find(x);
        int y_parent = Find(y);

        if(x_parent != y_parent){
            if(x_parent < y_parent) parent[y_parent] = x_parent;
            else parent[x_parent] = y_parent;
            return true;
        }
        return false;
    }
};

class Solution {
    DSU* network;
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        /* 
            TC - O(N)
            SC - O(N)
        */
        set<int> parents;
        network = new DSU(n);
        int excess = 0;
        for(auto i : connections){
            if(!network->Union(i[0], i[1])) excess++;
        }
        for(int i = 0; i < n; i++){
            parents.insert(network->Find(i));
        }
        // cout << excess << endl;
        if(excess >= parents.size() - 1) return parents.size() - 1;
        return -1;
    }
};