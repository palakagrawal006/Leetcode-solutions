class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<int> ans(n-k+1) ;
        deque <int> dq; 

        int i = 0 , j = 0; 
        while(i<n && j<n){
            while(!dq.empty() && dq.back()<nums[j]) dq.pop_back() ;

            dq.push_back(nums[j]) ; 

            if(j-i+1 == k) {
                ans[i] = dq.front() ; 
                if(dq.front() == nums[i]) dq.pop_front();
                i++;
            }

            j++;
        }
        return ans ;
    }
};