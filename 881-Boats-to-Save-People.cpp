class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        int n = arr.size() ; 
        int c = 0 ; 
        sort(arr.begin() , arr.end()) ; 
        int i =0 ;
        int j = n-1; 
        while(i<=j){
            if(arr[i]+arr[j] <= limit){
                c++; 
                j--;
                i++; 
            }
            else{
                c++; 
                j--; //j cant be pair with anyone
            }
        }
        return c; 
    }
};