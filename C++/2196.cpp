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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int, pair<int, int>> mp;
        map<int, bool> isHead;
        for(auto i : d){
            if(mp.count(i[0])){
                if(i[2]) mp[i[0]].first = i[1];
                else mp[i[0]].second = i[1];
                isHead[i[1]] = false;
                if(isHead.count(i[0]) == 0 || isHead[i[0]]) isHead[i[0]] = true;
            }else{
                if(i[2]) mp[i[0]] = {i[1], -1};
                else mp[i[0]] = {-1, i[1]};
                isHead[i[1]] = false;
                if(isHead.count(i[0]) == 0 || isHead[i[0]]) isHead[i[0]] = true;
            }
        }

        int h = -1;
        for(auto [k, v] : isHead) if(v) h = k;

        TreeNode* head = new TreeNode(h);
        queue<TreeNode*> q;
        q.push(head);
        while(q.size()){
            TreeNode* cur = q.front();
            if(mp.count(cur->val) && mp[cur->val].first != -1){
                cur->left = new TreeNode(mp[cur->val].first);
                q.push(cur->left);
            }
            if(mp.count(cur->val) && mp[cur->val].second != -1){
                cur->right = new TreeNode(mp[cur->val].second);
                q.push(cur->right);
            }

            q.pop();
        }
        return head;
    }
};