#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    TreeNode* createBST(vector<int>& v, int l, int r){
        if(l > r) return nullptr;
        int m = (l + r) >> 1;

        TreeNode* lf = createBST(v, l, m - 1);
        TreeNode* rg = createBST(v, m + 1, r);

        return new TreeNode(v[m], lf, rg);
    }

    TreeNode* balanceBST(TreeNode* root) {

        /* 
            TC - O(N)
            SC - O(N)
        */
        vector<int> v;
        inorder(root, v);

        return createBST(v, 0, v.size() - 1);
    }
};