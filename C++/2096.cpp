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
    string dfs(TreeNode* cur, int n){
        if(!cur) return "";
        if(cur->val == n) return "$";
        string l = "L" + dfs(cur->left, n);
        if(l.back() == '$') return l;
        string r = "R" + dfs(cur->right, n);
        if(r.back() == '$') return r;
        return "";
    }
public:
    string getDirections(TreeNode* root, int s, int d) {
        string sp = dfs(root, s);
        string dp = dfs(root, d);
        int i = 0;
        sp.pop_back();
        dp.pop_back();
        while(sp[i] == dp[i]) i++;
        string res = string(sp.size() - i, 'U');
        for(int j = i; j < dp.size(); j++) res += dp[j];
        return res;
    }
};