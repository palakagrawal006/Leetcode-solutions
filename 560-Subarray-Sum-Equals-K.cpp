// map 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() ;
        int c = 0 ;

        for(int i = 1; i<n; i++){
            nums[i] = nums[i-1]+nums[i] ; 
        }
        unordered_map <int , int> mp; 

        for(int i = 0; i<n; i++){
            if (nums[i] == k) c++;

            int rem = nums[i]-k;
            if(mp.find(rem) != mp.end()) c += mp[rem];
 
            mp[nums[i]]++; 
        }
        return c; 
    }
};


// // set 
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size() ;
//         int c = 0 ;

//         for(int i = 1; i<n; i++){
//             nums[i] = nums[i-1]+nums[i] ; 
//         }
//         unordered_set <int> s; 

//         for(int i = 0; i<n; i++){
//             if (nums[i] == k) c++;

//             int rem = nums[i]-k;
//             if(s.find(rem) != s.end()) c++; 
  
//             s.insert(nums[i]) ; 
//         }
//         return c; 
//     }
// };


// // prefix 
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size() ;
//         vector <int> prefix(n , 0) ; 
//         prefix[0] = nums[0] ; 
//         int c = 0 ;

//         for(int i = 1; i<n; i++){
//             prefix[i] = prefix[i-1]+nums[i] ; 
//         }

//         for(int i = 0; i<n; i++){
//             if(prefix[i]<k) continue; 
//             else if (prefix[i] == k) c++;
//             else {
//                 int ele = prefix[i]-k ; 
//                 int a = count(prefix.begin() , prefix.end() ,ele) ; 
//                 if(a>0) c++; 
//             }
//         }
//         return c; 
//     }
// };