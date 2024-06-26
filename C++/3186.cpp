class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {

        /* 
            TC - O(NlogN) [sorting] + O(NlogN) [2NlogN]
            SC - O(N)
        */
        sort(power.begin(), power.end()); // O(NlogN)
        int n = power.size();
        vector<long long> dp(n + 1, 0);
        long long res = 0;
        for(int i = 0; i < n; i++){
            //not selected
            dp[i + 1] = dp[i];
            //selected
            long long maxy = 0;
            long long j = i - 1;
            j = lower_bound(power.begin(), power.end(), power[i]) - power.begin(); // O(logN)
            maxy = (i - j + 1) * power[i];
            j = upper_bound(power.begin(), power.end(), power[i] - 3) - power.begin(); // O(logN)
            j = max(0ll, j - 1);
            if(abs(power[j] - power[i]) > 2)
                maxy = max(maxy, maxy + dp[j + 1]);
            dp[i + 1] = max(dp[i + 1], maxy);
            res = max(res, dp[i + 1]);
        }
        return res;
    }
};
