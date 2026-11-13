class Solution {
public:
    bool isprime(int n) {
        if(n== 1) return false; 
        for(int i= 2; i<=sqrt(n) ; i++){
            if(n%i == 0) return false;
        }
        return true; 
    }
    int heighestFactor(int n){
        
        for(int i= 2; i<=sqrt(n) ; i++){
            if(n%i ==0) return n/i; 
        }
        return 1;
    }
    int minSteps(int n) {
        if(n==1)return 0;
        if(isprime(n)) return n ; 

        int h = heighestFactor(n) ;
        return n/h + minSteps(h) ; 
    }
};