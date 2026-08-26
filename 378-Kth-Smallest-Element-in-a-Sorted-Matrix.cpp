// m2 -- all -- o(n^2*logn)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();

        // value, row, col
        priority_queue < vector<int>, vector<vector<int>>,
            greater<vector<int>>> pq; // min heap ; ;

        for (int i = 0; i < n; i++) {
            pq.push({arr[i][0], i, 0});
        }

        while (k) {
            auto curr = pq.top();
            pq.pop(); // top min val popped
            k--;

            int val = curr[0];
            int row = curr[1];
            int col = curr[2];

            if(k==0) return val ;

            if (col + 1 < m)
                pq.push({arr[row][col + 1], row, col + 1});
        }
        return -1;
    }
};


// // m1 -- all -- o(n^2*logn)
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& arr, int k) {
//         int n = arr.size();
//         int m = arr[0].size();

//         priority_queue<int> pq; // max heap ;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 pq.push(arr[i][j]);

//                 if (pq.size() == k + 1) {
//                     pq.pop();
//                 }
//             }
//         }
//         return pq.top();
//     }
// };