class Solution {
public:
    bool isperfectsq(int n) {
        int root = sqrt(n);
        if (root * root == n)
            return true;
        else
            return false;
    }
    bool judgeSquareSum(int c) {

        int lo = 0, hi = c;

        while (lo <= hi) {
            if (isperfectsq(lo) && isperfectsq(hi))
                return true;

            else if (!isperfectsq(hi)){
                hi = (int)sqrt(hi)* (int)sqrt(hi) ; 
                lo = c - hi ; 
            }
            else {
                lo = ((int)sqrt(lo)+1)* ((int)sqrt(lo)+1) ; 
                hi = c - lo ; 
            }
        }
        return false;
    }
};