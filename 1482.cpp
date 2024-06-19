class Solution {
public:
    bool check(int i, vector<int>& bloomDay, int m, int k){
        long long c = 0;
        for(int j = 0; j < bloomDay.size(); j++){
            if(bloomDay[j] <= i) c++;
            else{
                m -= c/k;
                c = 0;
            }
        }
        m -= c/k;
        if(m <= 0) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        /* 
            TC - O(NlogD) D - max element in bloomDay
            SC - O(1)
        */
        if(1ll * m * k > bloomDay.size()) return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int res = INT_MAX;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(mid, bloomDay, m, k)){
                res = min(res, mid);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return res;
    }
};
