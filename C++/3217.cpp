#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, int> mp;
        for(auto i : nums) mp[i]++;
        vector<int> res;
        while(head){
            if(!mp.count(head->val)) res.push_back(head->val);
            head = head->next;
        }

        ListNode* cur = new ListNode(-1);
        head = cur;
        for(auto i : res){
            cur->next = new ListNode(i);
            cur = cur->next;
        }
        return head->next;
    }
};