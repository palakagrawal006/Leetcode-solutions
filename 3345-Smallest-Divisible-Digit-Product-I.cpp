class Solution {
public:
    int product(int n) {
        int prod = 1;
        while (n > 0) {
            prod *= n % 10;
            n = n / 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {

        for (int i = n; i < n + 10; i++) {
            int prod = product(i);

            if (prod % t == 0)
                return i;
        }
        return -1;
    }
};