class Solution {
public:
    int arrangeCoins(int n) {
      int lo = 0, hi = n ;

     while(lo<=hi){
        long long k = lo+(hi-lo)/2;
        long long m = k*(k+1)/2;  

        if(m == n) return k; 
        else if(m>n) hi = k-1 ;
        else lo = k+1; 
        }

        return hi;
    }
};
// class Solution {
// public:
//     int arrangeCoins(int n) {
//         int x = 1 ;
//         while(n>=x){
//             n -= x ;
//             x++;
//         }
//         return x-1; 
//     }
// };