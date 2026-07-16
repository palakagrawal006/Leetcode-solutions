class Solution {
public:
    // int gcd(int first, int second){
    //     for(int i = min(first, second) ; i>=1 ; i--){
    //         if(first%i== 0 && second%i==0) return i ;
    //     }
    //     return 1;
    // }


    //     int gcd(int a, int b){
    //     while(b){
    //         int t = a % b;
    //         a = b;
    //         b = t;
    //     }
    //     return a;
    // }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> preGcd(n);
        int mx = INT_MIN;

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            preGcd[i] = gcd(nums[i], mx);
            cout << preGcd[i] << " ";
        }

        sort(preGcd.begin(), preGcd.end());

        int i = 0, j = n - 1;
        long long sum = 0;
        while (i < j) {
            sum += gcd(preGcd[i], preGcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};