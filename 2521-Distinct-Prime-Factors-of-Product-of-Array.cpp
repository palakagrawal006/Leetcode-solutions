class Solution {
public:
    void fillseive(vector<bool> &seive){
        int n = seive.size()-1; 
        for(int i= 2; i<=sqrt(n); i++){
            for(int j= i*2; j<=n; j+=i){
                seive[j] = 0; 
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size() ; 

        // find max of nums
        int mx = *max_element(nums.begin() , nums.end()) ; 

        // seive
        vector<bool> seive(mx+1 , 1); //prime
        fillseive(seive) ; 
        if(mx+1>0 )seive[0]  = 0 ; 
        if(mx+1>1)seive[1]  = 0 ; 

        // count prime no
        vector<int> primes; 
        for(int i = 2; i<=mx ; i++){
            if(seive[i]==1) primes.push_back(i);
        }

        // check if these prime number exists in nums ele
        vector<int> taken (primes.size() , 0) ; //none taken

        for(int i = 0; i<n ; i++){
           int ele = nums[i] ; 
            for(int j=0; j<primes.size() ; j++){
                if(primes[j]>ele) break; 
                if(ele % primes[j] ==0) {
                    taken[j] = 1; 
                }
            }
            
        }
        int ans = 0;
        for(int i = 0 ; i<taken.size() ; i++){
            if(taken[i]==1) ans++;
        }
        return ans;
    }
};