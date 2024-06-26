class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        int j = 0;
        long long reach = 0;
        int res = 0;
        while(reach < n){
            if(j < nums.size() && reach + 1 >= nums[j]){
                reach += nums[j++];
            }else{
                res++;
                reach += reach + 1;
            }
        }  
        return res;
    }
};
