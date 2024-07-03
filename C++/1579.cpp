#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);

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
            // merge sets
            if(rank[x_parent] < rank[y_parent]) parent[x_parent] = y_parent;
            else parent[y_parent] = x_parent;
            if(rank[x_parent] == rank[y_parent]) rank[x_parent]++;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        /* 
            TC - O(M) M - no of edges
            SC - O(N)
        */
        DSU alice(n + 1);
        DSU bob(n + 1);
        sort(edges.begin(), edges.end());
        int res = 0;

        int alice_edges = 0, bob_edges = 0;
        for(int i = edges.size() - 1; i >= 0; i--){
            switch(edges[i][0]){
                case 3 :    if(!alice.Union(edges[i][1], edges[i][2])) res++;
                            else{
                                alice_edges++;
                                bob.Union(edges[i][1], edges[i][2]);
                                bob_edges++;
                            }
                            break;
                case 2 :    if(!bob.Union(edges[i][1], edges[i][2])) res++;
                            else bob_edges++;
                            break;
                case 1 :    if(!alice.Union(edges[i][1], edges[i][2])) res++;
                            else alice_edges++;
                            break;
                default :   break;
            }
        }
        if(alice_edges == n - 1 && bob_edges == n - 1) return res;
        return -1;
    }
};