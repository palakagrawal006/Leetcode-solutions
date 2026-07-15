class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0 , sumEven = 0;

        for(int i = 1; i<= 2*n ; i+=2){
            sumOdd += i;
            sumEven += i+1; 
        }

        for(int i = min(sumOdd, sumEven) ; i>=1 ; i--){
            if(sumOdd%i== 0 && sumEven%i==0) return i ; 
        }
        return 1; 
    }
};