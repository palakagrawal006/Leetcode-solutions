class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1 ;
      if(n==2) return 2 ; 

      int sum1 = 1 ; 
      int sum2 = 2 ; 

      for(int i = 3; i<=n; i++){
       
        sum2 = sum1 + sum2 ; 
         sum1 = sum2-sum1 ;
      }
      return sum2; 

    }
};
// class Solution {
// public:
//     int climbStairs(int n) {
//       if(n==1)return 1 ;
//       if(n==2) return 2 ; 

//       return climbStairs(n-1) + climbStairs(n-2) ; 
//     }
// };