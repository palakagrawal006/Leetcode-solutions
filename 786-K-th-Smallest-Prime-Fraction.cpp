class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // smallest -- max heap 
        int n = arr.size() ; 
        priority_queue<pair<double , pair<int, int>>> pq; //fraction , i , j

        for(int i = 0 ; i<n; i++){
            for(int j = n-1; j>i ; j--){
                double frac = double(arr[i])/double(arr[j]);  
                pq.push({frac, {arr[i] , arr[j]}}) ; 

                if(pq.size()>k) pq.pop() ; 
            }
        }
        return {pq.top().second.first ,pq.top().second.second}; 
    }
};