class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> pq; // min heap

        for (int x : nums) {
            pq.push(x);
        }

        while (k > 0) {
            int min = pq.top() ; 
            pq.pop() ; 
            pq.push(-min) ; 
            cout<<pq.top()<<" " ; 
            k--;
        }

        int sum = 0;
        while(!pq.empty()){
            sum+= pq.top() ;
            pq.pop() ; 
        }
        return sum;
    }
};