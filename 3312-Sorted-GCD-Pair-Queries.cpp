class Solution {
public:
    void factors(vector<int>& f, int n) {

        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                f[i]++;
                if (n / i != i)
                    f[n / i]++;
            }
        }
    }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();

        // find max of array
        int maxi = nums[0];
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        vector<int> f(maxi + 1, 0);

        // find factors of each element -- freq of each
        for (int i = 0; i < n; i++) {
            factors(f, nums[i]);
        }

        // count no. of pairs
        // update pairs
        vector<long long> gcd(maxi + 1, 0);

        for (int i = maxi; i >= 1; i--) {
            long long count = f[i];

            // similar to combination
            gcd[i] = count * (count - 1) / 2;

            // correction/updation
            for (int j = i * 2; j <= maxi; j += i) {
                gcd[i] -= gcd[j];
            }
        }

        // cummulative sum
        for (int i = 1; i <= maxi; i++) {
            gcd[i] = gcd[i] + gcd[i - 1];
        }

        // binary search each queries
        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {

            int l = 1;
            int h = f.size() - 1;
            int temp = 1;

            while (l <= h) {
                int mid = l + (h - l) / 2;

                if (gcd[mid] > queries[i]) {
                    temp = mid;
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans[i] = temp;
        }

        return ans;
    }
};