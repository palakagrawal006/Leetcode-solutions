class Solution {
public:
    int bestClosingTime(string arr) {
        int n = arr.size()+1 ; 

        vector<int> yes(n, 0); //suff
        vector<int> no(n, 0); //pre

        // count y 
        yes[n-1] =0;
        for(int i = n-2; i>=0; i--){
            if(arr[i]=='Y')yes[i] = yes[i+1]+1; 
            else yes[i] = yes[i+1] ;  
        }

        // count n 
        no[0] = 0; 
        for(int i =1; i<n ; i++){
            if(arr[i-1]=='N') no[i] = no[i-1]+1; 
            else no[i] = no[i-1]  ;
        }

        int minIdx = -1; 
        int mini =INT_MAX; 
        for(int i = 0 ; i<n ; i++){
            int penalty = yes[i]+no[i] ; 
            if(penalty < mini){
                mini = penalty; 
                minIdx= i ;
            }
        }
        return minIdx ; 
    }
};