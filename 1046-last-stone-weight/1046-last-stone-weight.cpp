class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        int n = arr.size();

        priority_queue<int> pq; // max heap

        for (int x : arr) {
            pq.push(x);
        }

        while (pq.size() >= 2) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (x == y)
                continue;
            else
                pq.push(abs(y - x));
        }
        if(!pq.empty()) return pq.top() ;
        return 0 ; 
    }
};