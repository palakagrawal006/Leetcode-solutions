class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0 ;
        long long sum = 0 ;  

        while(n>0){
           
            int rem= n%10 ; 
            cout<<rem<<" " ; 

            if(rem >0){
                x = x*10 ; 
                x+=rem ;
                sum += rem ; 
                cout<< x<< " ";
            } 

            n = n/10 ; 
        }
        // reverse
        int p = 0 ;
        while(x>0){
           p = p*10 ;  
           p += x%10 ; 
           x/=10; 
        }

        sum = p*sum ; 
        return sum ; 

    }
};