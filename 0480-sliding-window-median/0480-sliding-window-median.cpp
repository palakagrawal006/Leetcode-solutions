class Solution {
public:

    priority_queue<int> left; 
    priority_queue<int, vector<int>, greater<int>> right;

    unordered_map<int, int> mp;

    int x = 0; // valid elements in left
    int y = 0; // valid elements in right


    // Remove all invalid elements from heap tops
    void pruneLeft() {
        while (!left.empty() && mp[left.top()] > 0) {
            int val = left.top();
            left.pop();

            mp[val]--;

            if (mp[val] == 0)
                mp.erase(val);
        }
    }

    void pruneRight() {
        while (!right.empty() && mp[right.top()] > 0) {
            int val = right.top();
            right.pop();

            mp[val]--;

            if (mp[val] == 0)
                mp.erase(val);
        }
    }


    void balance() {

        pruneLeft();
        pruneRight();

        // left should have either:
        // same number as right
        // OR one extra

        if (x > y + 1) {

            right.push(left.top());
            left.pop();

            x--;
            y++;
        }

        else if (x < y) {

            left.push(right.top());
            right.pop();

            x++;
            y--;
        }

        pruneLeft();
        pruneRight();
    }


    void add(int val) {

        pruneLeft();
        pruneRight();

        if (left.empty() || val <= left.top()) {
            left.push(val);
            x++;
        }
        else {
            right.push(val);
            y++;
        }

        balance();
    }


    void remove(int val) {

        pruneLeft();
        pruneRight();

        mp[val]++;

        // Decide which logical heap the outgoing
        // element belongs to.

        if (val <= left.top())
            x--;
        else
            y--;

        pruneLeft();
        pruneRight();

        balance();
    }


    double getMedian() {

        pruneLeft();
        pruneRight();

        if (x + y & 1)
            return left.top();

        return ((double)left.top() + right.top()) / 2.0;
    }


    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        // First window
        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }

        ans.push_back(getMedian());

        // Sliding
        for (int i = k; i < nums.size(); i++) {

            // Remove outgoing
            remove(nums[i - k]);

            // Add incoming
            add(nums[i]);

            ans.push_back(getMedian());
        }

        return ans;
    }
};
// class Solution {
// public:
//     double getMedian(priority_queue<int>& left,
//                      priority_queue<int, vector<int>, greater<int>>& right,
//                      int x, int y) {
//         int total = x + y;

//         if (total % 2 != 0)     // odd
//             return right.top(); // min m zyda hoga
//         else
//             return (left.top() + right.top()) / 2.0; // even
//     }

//     bool isBalanced(int x, int y) { return (x == y) or (x - 1 == y); }

//     vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         priority_queue<int> left;                             // max
//         priority_queue<int, vector<int>, greater<int>> right; // min heap
        
//         unordered_map<int, int> mp; // lazy deletion map

//         vector<double> ans;

//         int x = 0, y = 0; // initial size of both heaps
//         // x = max , y = min

//         right.push(nums[0]);
//         y++; // min size increase

//         // first window
//         for (int i = 1; i < k; i++) {
//             int curr = nums[i];
//             double med = getMedian(left, right, x, y);
//             if (curr > med) {
//                 right.push(curr);
//                 y++;

//                 if (!isBalanced(x, y)) {
//                     // right ka top left m dal do
//                     left.push(right.top());
//                     right.pop();
//                     x++; y-- ; 
//                 }
//             } else {
//                 left.push(curr);
//                 x++;

//                 if (!isBalanced(x, y)) {
//                     right.push(left.top());
//                     left.pop();
//                     x--; y++; 
//                 }
//             }
//         }
//         double med = getMedian(left, right, x, y); // ans of first window
//         ans.push_back(med);
//         for (int i = k; i < n; i++) {
//             int newIdx = i;
//             int oldIdx = i - k; // idx to be deleted

//             double med = getMedian(left, right, x, y);
//             int curr = nums[newIdx];
//             if (curr > med) {
//                 right.push(curr);
//                 y++;

//                 if (!isBalanced(x, y)) {
//                     // right ka top left m dal do
//                     left.push(right.top());
//                     right.pop();
//                     x++; y-- ; 
//                 }
//             } else {
//                 left.push(curr);
//                 x++;

//                 if (!isBalanced(x, y)) {
//                     right.push(left.top());
//                     left.pop();
//                     x-- ; y++; 
//                 }
//             }
//             while (!left.empty() && mp[left.top()]) {
//                 mp.erase(left.top());
//                 left.pop();
//                 x--;

//                 if (!isBalanced(x, y)) {
//                     // right ka top left m dal do
//                     left.push(right.top());
//                     right.pop();
//                 }
//             }
//             while (!right.empty() && mp[right.top()]) {
//                 mp.erase(right.top());
//                 right.pop();
//                 y--;
//                 if (!isBalanced(x, y)) {
//                     right.push(left.top());
//                     left.pop();
//                 }
//             }
//             med = getMedian(left, right, x, y);
//             ans.push_back(med);
//         }

//         return ans;
//     }
// };
