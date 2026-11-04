class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size() ; 
        int sum = 0;
        int count = 0 ;

        int i = 0, j =0 ;
        while(i<n && j<n){
            sum += arr[j] ;

            if(j-i+1 >k){
                sum -= arr[i] ;
                i++;
            }

            if(j-i+1 ==k){
                int avg = sum / (j-i+1) ; 
                if(avg >= threshold) count++;
            }
            j++; 
        }

        return count  ;
    }
};