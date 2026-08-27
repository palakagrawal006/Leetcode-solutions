class Solution {
public:
    typedef pair<double, pair<int, int>> p;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // smallest -- min heap
        int n = arr.size();
        priority_queue<p, vector<p>, greater<p>> pq; // fraction , i , j

        for (int i = 0; i < n - 1; i++) { // smallest fraction
            double frac = double(arr[i]) / double(arr[n - 1]);
            pq.push({frac, {i, n - 1}}); // logn
        }

        while (k > 1) {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            double f = pq.top().first;
            pq.pop(); // its min - remove - search little bada for kth smallest
            k--;

            if (j - 1 > i) {
                double frac = double(arr[i]) / double(arr[j - 1]);
                ;
                pq.push({frac, {i, j - 1}}); // logn
            }
        }
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        return {arr[i], arr[j]};
    }
};

/////O(n^2logk)
// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         // smallest -- max heap
//         int n = arr.size() ;
//         priority_queue<pair<double , pair<int, int>>> pq; //fraction , i , j

//         for(int i = 0 ; i<n; i++){ // n^2
//             for(int j = n-1; j>i ; j--){
//                 double frac = double(arr[i])/double(arr[j]);
//                 pq.push({frac, {arr[i] , arr[j]}}) ;  //logk

//                 if(pq.size()>k) pq.pop() ;  // logk
//             }
//         }
//         return {pq.top().second.first ,pq.top().second.second};
//     }
// };