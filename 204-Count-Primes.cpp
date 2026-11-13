// tle 
class Solution {
public:
    void fillseive(vector<bool> &seive) {
        int n = seive.size()-1;

        for(int i = 2; i<=sqrt(n); i++){
            for(int j = 2*i ; j<=n; j=j+i){
                seive[j] = 0; //composite
            }
        } 
    }
    int countPrimes(int n) {
        vector<bool> seive(n+1 , 1) ; //all prime
        fillseive(seive) ; 

        seive[0] = 0; 
        seive[1] = 0; // 1 is not prime 

        int ans= 0 ; 
        for(int i =2; i<n ; i++){
            if(seive[i]==1) ans++;
        }
        return ans; 

    }
};

// // tle 
// class Solution {
// public:
//     bool isprime(int n) {
//         if(n== 1) return false; 
//         for(int i= 2; i<=sqrt(n) ; i++){
//             if(n%i == 0) return false;
//         }
//         return true; 
//     }
//     int countPrimes(int n) {
//         int ans = 0; 
//         for(int i = 2; i<n; i++){
//             if(isprime(i)){
//                 ans++; 
//                 cout<<i <<" " ; 
//             }
//         }
//         return ans ;
//     }
// };