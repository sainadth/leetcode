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
    int del[1001]{0};
    vector<TreeNode*> res;
public:
    void dfs(TreeNode* cur, int deleted){
        if(!cur) return;
        if(del[cur->val]){
            dfs(cur->left, 1);
            dfs(cur->right, 1);
        }else{
            if(deleted) res.push_back(cur);
            if(cur->left && del[cur->left->val]){
                dfs(cur->left, 1);
                cur->left = nullptr;
            }else dfs(cur->left, 0);
            if(cur->right && del[cur->right->val]){
                dfs(cur->right, 1);
                cur->right = nullptr;
            }else dfs(cur->right, 0);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto i : to_delete) del[i] = 1;
        if(!del[root->val]) res.push_back(root);
        dfs(root, 0);
        return res;
    }
};