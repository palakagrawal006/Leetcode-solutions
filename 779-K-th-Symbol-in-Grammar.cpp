class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0 ;

        if(k%2==0){
            int prevEle = kthGrammar(n-1, k/2);

            if(prevEle == 1) return 0;
            else return 1; 
        }

        else{
            int prevEle = kthGrammar(n-1, k/2+1);
            return prevEle; 
        }

        return -1; 
    }
};