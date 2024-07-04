#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        ListNode* cur = head -> next;
        while(cur && cur -> next){
            if(cur->next->val == 0){
                cur->next = cur->next->next;
                cur = cur->next;
            }else{
                cur->val += cur->next->val;
                cur->next = cur->next->next;
            }
        }
        return head->next;
    }
};