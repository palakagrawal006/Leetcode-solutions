class Solution {
public:
    int countDigits(int num) {
        int ans = 0 ; 

        int n = num ; 

        while(n>0){
            int dig = n%10 ; 
            n = n/10;

            if( num % dig ==0 ) ans++; 
        }
        return ans; 
    }
};