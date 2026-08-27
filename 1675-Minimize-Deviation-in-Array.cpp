class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int mn  = INT_MAX; 

        //multiply all odd no ;
        for (int i = 0; i <n ; i++){
            if(nums[i]%2!=0) nums[i] = nums[i]*2; 
            mn = min(mn, nums[i]) ; 
        }

        priority_queue<int> pq;    // max heap ;
     
        for (int x : nums) {
            pq.push(x);
        }

        int mx = pq.top() ; 
        int diff = mx-mn ; //reduce dif - minimize mx by dividing

        while(pq.top() % 2==0){
            mx = pq.top() ;
            pq.pop() ; 

            mx = mx/2 ;
            pq.push(mx) ;
            mn = min(mn, mx) ; 
            diff = min(diff , pq.top()-mn) ; // curr max 
        }

        return diff ; 

    }
};