#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int res = 0;
    vector<int> dfs(TreeNode* cur, int distance){
        vector<int> l, r;
        if(cur->left) l = dfs(cur->left, distance);
        if(cur->right) r = dfs(cur->right, distance);
        if(l.size() == 0 && r.size() == 0) return {1};
        for(auto i : l) for(auto j : r) if(i + j <= distance) res++;
        for(auto &i : l) i++;
        for(auto &i : r) i++;
        for(auto i : r) l.push_back(i);
        return l;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return res;
    }
};