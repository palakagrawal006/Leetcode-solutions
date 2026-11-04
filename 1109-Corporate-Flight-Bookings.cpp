class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int s = bookings.size() ; 
        vector<int> ans(n) ; 

        for(int i = 0; i<s; i++){
            int first = bookings[i][0] , last = bookings[i][1] , seats = bookings[i][2];

            for(int j = first-1 ; j<=last-1; j++){
                ans[j] += seats ; 
            }
        }
        return ans ;
    }
};