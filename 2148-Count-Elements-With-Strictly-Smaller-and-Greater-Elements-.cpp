class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size() ;  

        // // nge
        // vector <int> nge(n)  ;
        // nge[n-1] = -1;

        // for(int i = n-2; i>=0; i--){
        //     nge[i] = max(nge[i+1] , nums[i+1]) ; 
        // }

        // // pge  in nge 

        sort(nums.begin() , nums.end()) ;
        int count=0;

        for(int i = 1; i<n-1; i++){
            if(nums[i] > nums[0] && nums[i]<nums[n-1])count++; 
        }

        return count;  
    }
};