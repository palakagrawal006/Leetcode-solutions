class Solution {
public:
    int maxSatisfied(vector<int>& arr, vector<int>& grumpy, int minutes) {
        int n = arr.size() ; 

        int i = 0, j = 0 ;
        int maxSum = 0 ;
        int maxIdx = -0 ;
        int sum = 0 ; 

        // find max loss of customers
        while(i<n && j<n){
            if(grumpy[j] == 1) sum += arr[j] ; 

            if(j-i+1>minutes){
                if(grumpy[i]==1) sum -= arr[i] ;
                i++;
            }

            if(maxSum< sum){
                maxSum = sum; 
                maxIdx= i ; 
            }
            j++; 
        }

        // update grumpy
        for(int i = maxIdx ; i<maxIdx+ minutes ; i++){
            grumpy[i] = 0; 
        }

        // max sum 
        int ans = 0; 
        for(int i= 0; i<n; i++){
            if(grumpy[i]==0) ans += arr[i] ;
        }
        return ans ;
    }
};