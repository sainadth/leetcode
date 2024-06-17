class Solution {
public:
    bool isSquare(long long n){
        long long x = floor(sqrt(n));
        if(x * x == n) return true;
        return false;
    }
    bool judgeSquareSum(int c) {
        /* 
            TC - O(N)
            SC - O(1)
        */
        for(long long i = 0; i * i <= c/2; i++){
            if(isSquare(c - i * i)) return true;
        }
        return false;
    }
};
