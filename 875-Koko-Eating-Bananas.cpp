class Solution {
public:
    long long countHour(vector<int>& arr, int cap){
        int n = arr.size() ; 

        long long hours = 0 ;
        int i = 0 ;
        while(i<n){
            if(arr[i] <= cap) hours++;
            else {
                hours+= (long long)arr[i]/cap; 
                if(arr[i]%cap!= 0) hours++; //for extra ints  
            }
            i++;
        }
        return hours; 
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size() ; 

        int lo = 1 , hi = INT_MIN ;

        for(int x : arr) hi = max(hi, x) ;

        int ans = -1;

        while(lo<=hi){
            int cap = lo+(hi-lo)/2; //capacity
            long long counth = countHour(arr, cap) ;
            cout<<counth;

            if(counth <= (long long)h) {
                ans = cap;  
                hi = cap-1;
            }
            else {
                lo = cap+1 ;
            }
        }

        return ans ; 
    }
};