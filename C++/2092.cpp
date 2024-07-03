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

    void Union(int x, int y){
        int x_parent = Find(x);
        int y_parent = Find(y);

        if(x_parent != y_parent){
            if(x_parent < y_parent) parent[y_parent] = x_parent;
            else parent[x_parent] = y_parent;
        }
    }

    void Reset(int x){
        parent[x] = x;
    }
};


class Solution {
    DSU* network;
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        /* 
            TC - O(N)
            SC - O(N)
        */
        network = new DSU(n);
        map<int, set<pair<int, int>>> mp; /* meetings sorted as per time */
        for(auto i : meetings){
            mp[i[2]].insert({i[0], i[1]});
        }

        network->Union(0, firstPerson); /* Adding firstPerson to network {0, firstPerson} */
        for(auto [k, v] : mp){
            vector<int> pool;
            for(auto i : v){
                if(network -> Find(i.first) != 0 && network -> Find(i.second) != 0){ /* If not part of network {0} create a temporary network (pool) */
                    pool.push_back(i.first);
                    pool.push_back(i.second);
                }
                network -> Union(i.first, i.second);
            }
            for(auto i : pool)
                if(network -> Find(i) != 0) network -> Reset(i); /* If node is not connected to {0} then remove it from temporary network */
        }

        vector<int> res;
        for(int i = 0; i < n; i++){
            if(network -> Find(i) == 0) res.push_back(i); /* Adding all connected nodes in network */
        }

        return res;
    }
};