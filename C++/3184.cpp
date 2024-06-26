class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        /* 
            TC - O(N * N)
            SC - O(1)
        */
        int n = hours.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++)
                if((hours[i] + hours[j]) % 24 == 0) res++;
        }
        return res;
    }
};

/* 
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        
            TC - O(N)
            SC - O(N)
       
        map<int, long long> mp;
        long long res = 0;

        for(auto i : hours){
            mp[i % 24]++;
        }
        
        for(auto [k, v] : mp){
            int counter = (24 - k) % 24;
            if(mp.count(counter) == 0) continue;
            if(counter == k){
                res += v * (v - 1) / 2;
            }else
                res += mp[k] * mp[counter];
            mp[k] = 0;
        }
        
        return res;
    } 
};
*/
