#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    vector<int> tree;
    vector<bool> lazy;
public:
    SegmentTree(vector<int>& nums){
        int n = nums.size();
        tree.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, false);
        build(1, 0, n - 1, nums);
    }

    void build(int i, int l, int r, vector<int>& nums){
        if(l == r){
            tree[i] = nums[l];
            return;
        }
        int m = (l + r) >> 1;
        build(i << 1, l, m, nums);
        build(i << 1 | 1, m + 1, r, nums);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    /* Range Count Query - RCQ */
    int RCQ(int i, int l, int r, int rL, int rR){
        if(rL > rR) return 0;
        if(l == rL && r == rR) return tree[i];
        int m = (l + r) >> 1;
        push(i, l, r);
        return RCQ(i << 1, l, m, rL, min(m, rR)) + RCQ(i << 1 | 1, m + 1, r, max(m + 1, rL), rR); /* Count of 1's in the segment     */
    }

    void push(int i, int l, int r){
        if(lazy[i]){
            int m = (l + r) >> 1;
            update(i << 1, l, m);
            update(i << 1 | 1, m + 1, r);
            lazy[i] = false;
        }
    }

    void update(int i, int l, int r){
        tree[i] = (r - l + 1) - tree[i];    /* Toggle no of 1's in the segment */
        lazy[i] = !lazy[i];
    }

    void lazy_update(int i, int l, int r, int rL, int rR){
        if(rL > rR) return;
        if(l == rL && r == rR){
            update(i, l, r);
            return;
        }
        int m = (l + r) >> 1;
        push(i, l, r);
        lazy_update(i << 1, l, m, rL, min(m, rR));
        lazy_update(i << 1 | 1, m + 1, r, max(m + 1, rL), rR);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    int get(int i, int l, int r, int k){
        if(l == r) return tree[i];
        int m = (l + r) >> 1;
        push(i, l, r);
        if(k <= m) return get(i << 1, l, m, k);
        return get(i << 1 | 1, m + 1, r, k);
    }
};

class Solution {
    SegmentTree* s;
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        s = new SegmentTree(nums);
        int n = nums.size();
        int res = 0;

        for(int i = 0; i < n - k + 1; i++){
            int cur = s -> get(1, 0, n - 1, i);
            if(!cur){
                s->lazy_update(1, 0, n - 1, i, i + k - 1);
                res++;
            }
        }

        if(k > 1){
            int cnt = s -> RCQ(1, 0, n - 1, n - k + 1, n - 1);
            if(cnt != k - 1) return -1;
        }

        delete s;
        return res;
    }
};