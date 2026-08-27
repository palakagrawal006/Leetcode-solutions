class Solution {
public:
    typedef pair<int, pair<int, int>> p; 
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(); 

        priority_queue<p, vector<p> , greater<p>> pq; // min heap - val ,row, col 

        int mx = INT_MIN, start= nums[0][0], end; 

        for(int i = 0 ;i<k; i++){
            pq.push({nums[i][0] ,{ i, 0}}) ;
            mx = max(mx, nums[i][0]) ; 
            start = min(start , nums[i][0]);
            end = mx; 
        }
        
        while(true){ 
            auto mins = pq.top() ;  // minimum of min heap
            int val = mins.first ; 
            int row = mins.second.first;
            int col = mins.second.second;

            pq.pop() ; 
            if(nums[row].size()>col+1){
                pq.push({nums[row][col+1] , {row, col+1}}) ; 
                mx = max(mx, nums[row][col+1]);
                if(mx-pq.top().first < end-start){
                    start = pq.top().first ; 
                    end = mx ; 
                }
            }
            else return {start , end} ; 
        }
        return {-1,-1}; 
    }
}; 