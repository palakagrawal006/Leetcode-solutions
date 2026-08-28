class Solution {  //O(n + k log n)
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin() , nums.end()); // min heap o(n)

        int sum = 0 ; 
        for (int x : nums) { // o(n)
            sum += x; 
        }

        while (k > 0) { //o(k logn)
            int min = pq.top() ; 

            if(min == 0) break ; //same sum 
            pq.pop() ;
            sum -= min; 
            pq.push(-min) ; 
            sum += (-min);
            k--;
        }
        return sum;
    }
};


// class Solution {  //O((n + k) log n)
// public:
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         int n = nums.size();

//         priority_queue<int, vector<int>, greater<int>> pq; // min heap

//         for (int x : nums) { // o(nlogn)
//             pq.push(x);
//         }

//         while (k > 0) { //o(k logn)
//             int min = pq.top() ; 
//             pq.pop() ; 
//             pq.push(-min) ; 
//             cout<<pq.top()<<" " ; 
//             k--;
//         }

//         int sum = 0;
//         while(!pq.empty()){  // nlogn
//             sum+= pq.top() ;
//             pq.pop() ; 
//         }
//         return sum;
//     }
// };