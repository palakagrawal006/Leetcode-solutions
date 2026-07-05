class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();

// mwethod 2 -- quick sort
       int lo = 0 ;
       int mid = 0 ;
       int hi = n-1 ; 

       while(mid <= hi){
            if(nums[mid] == 0) {
                swap(nums[mid] ,nums[lo] ) ;
                lo++;
                mid++;
            } 
            else if(nums[mid] == 2) {
                swap(nums[mid] ,nums[hi] ) ;
                hi-- ; 
            } 
            else mid++ ;
       }
    }
};

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
        
//         int n = nums.size();

// // mwethod 1 -- 2 pass
//         int count0 = 0;
//         int count1 = 0 ;
//         int count2 = 0 ;
//         for (int i = 0 ; i<n ; i++){
//             if(nums[i] == 0) count0++;
//             else if(nums[i] == 1) count1 ++ ;
//             else count2 ++ ;
//         }

//         for(int i = 0 ; i<n ; i++){
//             if(count0 > 0){
//                nums[i] = 0 ;
//                count0-- ; 
//             } 
//             else if(count1 > 0){
//                nums[i] = 1 ;
//                count1-- ; 
//             } 
//             else  nums[i] = 2 ;
//         }
//     }
// };