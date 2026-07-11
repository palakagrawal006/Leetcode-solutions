class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        int n = queries.size(); // rows
        const int MOD = 1e9 + 7;

        vector<long long> preSum(m + 1, 0);
        vector<long long> preNum(m + 1, 0);
        vector<long long> pow10(m + 1, 1);
        vector<int> preCount(m + 1, 0); //count non zero
        vector<int> ans;

        for (int i = 1; i <= m; i++) {

            int d = s[i - 1] - '0';

            preSum[i] = (preSum[i - 1] + d) % MOD;
            pow10[i] = (pow10[i - 1] * 10) % MOD;

            if(d==0){
                preNum[i] = preNum[i - 1];
                preCount[i] = preCount[i - 1];
            }
            else {
                 preNum[i] = (preNum[i - 1] * 10 + d) % MOD;
                 preCount[i] = preCount[i - 1] + 1;
            }
        }

        for (auto q : queries) {
            int l = q[0], r = q[1];

            long long sum = (preSum[r + 1] - preSum[l] + MOD) % MOD;
           int nonZeroDigits = preCount[r + 1] - preCount[l]; 
            
            long long removedPrefix = (preNum[l] * pow10[nonZeroDigits]) % MOD;
            long long num = (preNum[r + 1] - removedPrefix + MOD) % MOD;

            ans.push_back((sum * num) % MOD);
        }

        return ans;
    }
};