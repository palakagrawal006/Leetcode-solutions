class Solution {
public:
    bool isPerfectSquare(int x) {
        int lo = 1, hi = x; 
        int ans= -1;

        while(lo<=hi){
            long long mid= lo + (hi-lo)/2;
            long long sq = mid*mid ;

            if(sq==x)return true;
            else if (sq > x) hi = mid-1; 
            else lo = mid+1; 
        }
      return false ; 
    }
};



