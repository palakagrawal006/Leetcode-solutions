class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin(), nums.end()); //[1,2,4,5]
        // sort(queries.begin() , queries.end()) ;

        // prefix -- [1,3,7,12]
        for (int i = 1; i < n; i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        vector<int> ans(m);

        for (int i = 0; i < m; i++) {
            int len = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] > queries[i])
                    break;
                else
                    len++;
            }
            ans[i] = len;
        }
        return ans; 
    }
};