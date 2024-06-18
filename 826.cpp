class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        /* 
            TC - O(NlogN) [sorting]
            SC - O(N) [dp]
        */

        int n = difficulty.size();

        vector<pair<int, int>> dp;

        for(int i = 0; i < n; i++)
            dp.push_back({profit[i], difficulty[i]});
    
        sort(dp.begin(), dp.end());             //O(NlogN)
        sort(worker.begin(), worker.end());     //O(NlogN)

        int res = 0;
        

        int i = worker.size() - 1;
        while(i >= 0){
            if(dp.size() == 0) break;
            if(dp.back().second <= worker[i]) {
                res += dp.back().first;
                i--;
            }
            else dp.pop_back();                 //O(1)
        }
        return res;
    }
};
