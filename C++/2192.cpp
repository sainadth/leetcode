#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        /* 
            TC - O(N * N + N * M) 
            SC - O(N + M)
        */

        vector<vector<int>> adjList(n, vector<int>(0));
        sort(edges.begin(), edges.end());
        for(auto i : edges){
            adjList[i[0]].push_back(i[1]);
        }

        vector<set<int>> res(n);

        for(int i = 0; i < n; i++){                     //O(N)
            vector<bool> vis(n, false);
            queue<int> q;
            q.push(i);
            while(q.size()){
                for(auto child : adjList[q.front()]){   //O(N + M)
                    if(!vis[child]){
                        q.push(child);
                        res[child].insert(i);
                    }
                }
                vis[q.front()] = true;
                q.pop();
            }
        }

        vector<vector<int>> v;
        for(auto i : res){
            vector<int> temp(i.begin(), i.end());
            v.push_back(temp);
        }
        return v;
    }
};