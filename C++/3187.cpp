class SegmentTree{
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& nums){
        n = nums.size();
        tree.resize(4 * n + 1, 0);
        build(0, 0, n - 1, nums);
    }

    bool isPeak(int i, vector<int>& nums){
        if(i > 0 && i < (nums.size() - 1)) return (nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]);
        return false;
    }

    void build(int i, int l, int r, vector<int>& nums){
        if(l == r){
            tree[i] = isPeak(l, nums);
            return;
        }
        int m = (l + r) / 2;
        build(2 * i + 1, l, m, nums);
        build(2 * i + 2, m + 1, r, nums);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    int RPQ(int i, int l, int r, int rl, int rr){
        if(rl > rr) return 0;
        if(l == rl && r == rr) return tree[i];
        int m = (l + r) / 2;
        return RPQ(2 * i + 1, l, m, rl, min(m, rr)) + RPQ(2 * i + 2, m + 1, r, max(m + 1, rl), rr);
    }

    void update(int i, int l, int r, int k, vector<int>& nums){
        if(l == r){
            tree[i] = isPeak(l, nums);
            return;
        }
        int m = (l + r) / 2;
        if(k <= m)
            update(2 * i + 1, l, m, k, nums);
        else 
            update(2 * i + 2, m + 1, r, k, nums);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
};

class Solution {
    SegmentTree* s;
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        /* 
            TC - O(QlogN)
                Q = no of queries
            SC - O(N)
        */
        s = new SegmentTree(nums);
        int n = nums.size();
        vector<int> res;
        for(auto i : queries){
            if(i[0] == 1){
                res.push_back(s->RPQ(0, 0, n - 1, i[1] + 1, i[2] - 1)); //logN
            }else{
                /* 
                    updating a node effects adjacent nodes as well so we need to check i - 1 and i + 1 as well
                */
                nums[i[1]] = i[2];
                s->update(0, 0, n - 1, i[1], nums);
                if(i[1] > 0) s->update(0, 0, n - 1, i[1] - 1, nums);    //logN
                if(i[1] < n - 1) s->update(0, 0, n - 1, i[1] + 1, nums);//logN
            }
        }
        return res;
    }
};
