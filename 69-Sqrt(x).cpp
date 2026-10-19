class Solution {
public:
    int mySqrt(int x) {
        int lo = 1, hi = x-1; 
        int ans= -1;

        while(lo<=hi){
            long long mid= lo + (hi-lo)/2;
            long long sq = mid*mid ;

            if(sq<=x) {
                ans  = mid; 
                lo= mid+1; 
            }
            else if (sq > x) hi = mid-1; 

        }
      return  (ans==-1)? x : ans ; 
    }
};