#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        /* 
            TC - O(N)
            SC - O(N)
        */
        vector<int> crit;
        bool g = 0, l = 0;
        ListNode* cur = head -> next;
        if(cur->val > head->val) g = 1;
        if(cur->val < head->val) l = 1;
        int i = 1;
        while(cur->next){
            if(g && cur->val > cur->next->val) crit.push_back(i);
            if(l && cur->val < cur->next->val) crit.push_back(i);
            l = g = 0;
            if(cur->val > cur->next->val) l = 1, g = 0;
            if(cur->val < cur->next->val) l = 0, g = 1;
            cur = cur->next;
            i++;
        }
        int miny = INT_MAX;
        for(int i = 1; i < crit.size(); i++){
            miny = min(miny, crit[i] - crit[i - 1]);
        }
        if(crit.size() < 2) return {-1, -1};
        return {miny, crit.back() - crit[0]};
    }
};