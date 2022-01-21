class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        bool neg = n<0;
        n = abs(n);
        double y = myPow(x,n/2);
        double soln;
        if(n&1) soln = x*y*y;
        else soln = y*y;
        if(neg) return 1.0/soln;
        return soln;
    }
};