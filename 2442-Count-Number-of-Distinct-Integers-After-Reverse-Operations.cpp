class Solution {
public:
    int reverse(int ele) {
        int x = 0;
        while (ele > 0) {
            x = x * 10;
            x += ele % 10;
            ele = ele / 10;
        }
        return x;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;

        for (int ele : nums){
            s.insert(ele) ;
            int x = reverse(ele);
            s.insert(x) ;
        }
        return s.size();
    }
};
// class Solution {
// public:
//     int reverse(int ele) {
//         int x = 0;
//         while (ele > 0) {
//             x = x * 10;
//             x += ele % 10;
//             ele = ele / 10;
//         }
//         return x;
//     }
//     int countDistinctIntegers(vector<int>& nums) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             int x = reverse(nums[i]);
//             nums.push_back(x);
//         }

//         for (int x : nums)
//             cout << x << " ";

//         unordered_set<int> s(nums.begin(), nums.end());
//         return s.size();
//     }
// };