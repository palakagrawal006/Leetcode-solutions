

// map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() ; 

        for(int i = 1 ; i<n ; i++){
            nums[i] = nums[i-1]+nums[i] ; 
        }

        int c = 0 ;
        unordered_map <int, int> mp ; 
        for(int i= 0 ; i<n; i++){
            if (nums[i]==k) c++;
           
            int rem = nums[i]-k; 
            
            if (mp.find(rem)!= mp.end()) c+= mp[rem];   
            mp[nums[i]]++; 
        }
        return c ; 
    }
};

// // set - doesnt store no. of times it comes
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size() ; 

//         for(int i = 1 ; i<n ; i++){
//             nums[i] = nums[i-1]+nums[i] ; 
//         }

//         int c = 0 ;
//         unordered_set <int> s ; 
//         for(int i= 0 ; i<n; i++){
//             if (nums[i]==k) c++;
           
//             int rem = nums[i]-k; 
            
//             if (s.find(rem)!= s.end()) c++;  
//             s.insert(nums[i]) ;  
            
//         }
//         return c ; 
//     }
// };


// wrong
// class Solution {
// public:
// // prefix 
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size() ; 

//         for(int i = 1 ; i<n ; i++){
//             nums[i] = nums[i-1]+nums[i] ; 
//         }

//         int c = 0 ;
//         for(int i= 0 ; i<n; i++){
//             if(nums[i]< k) continue; 
//             else if (nums[i]==k) c++;
//             else {
//                 int rem = nums[i]-k; 
//                 int e = count(nums.begin() , nums.end() , rem); 
//                 if(e>0) c++ ; 
//             }
//         }
//         return c ; 
//     }
// };