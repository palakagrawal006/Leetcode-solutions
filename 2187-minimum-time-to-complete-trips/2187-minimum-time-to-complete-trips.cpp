class Solution {
public:
    long long helper(vector<int>& time, long long mid){
        long long ans= 0 ;

        for(int i =0 ; i<time.size(); i++){
            ans += mid/(long long)time[i] ; 
        }
        return ans ;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long maxi = time[0] ; 
        for(int i = 0 ; i<n; i++){
            maxi = max(maxi , (long long) time[i]);
        }
        long long lo = 1, hi = maxi*(long long)totalTrips;
        long long ans = -1;

        while(lo<= hi){
            long long mid = lo+(hi-lo)/2;
            long long minTrip = helper(time, mid ); // mid time m kitni trips

            if(minTrip >= totalTrips){
                ans = mid; 
                hi = mid-1; 
            }
            else {
                
                 lo = mid+1;
            }
        }
        return ans ; 
    }
};