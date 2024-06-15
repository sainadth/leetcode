class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        /* 
            Adding elemets only when requiredCapital is <= capital 
            TC -  O(NlogN) [sorting] + O(KlogN + NlogN) [k times for poping from pq - KlogN, wc insert all n elements into pq - NlogN]
               -  O(NlogN) + O(KlogN) + O(NlogN)
               -  O(NlogN) + O(KlogN)
            SC - O(N) [for pq/cp]
        */
        int n = profits.size();
        priority_queue<pair<int, int>> pq;
        vector<pair<int, int>> cp;
        for(int i = 0; i < n; i++) cp.push_back({capital[i], profits[i]});
        sort(cp.begin(), cp.end()); // O(NlogN)
        int i = 0;
        while(k){
            while(true){
                if(i < cp.size() && cp[i].first <= w){
                    pq.push({cp[i].second, cp[i].first}); //O(logN)
                    i++;
                }
                else break;
            }
            if(pq.size()){
                w += pq.top().first;
                k--;
                pq.pop(); //O(logN)
            }else break;
        }
        return w;
    }
};
