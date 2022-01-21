class Solution {
public:
    double myPow(double a, int n) {
        bool neg = n<0;
        n = abs(n);
        double soln = 1.0;
        while(n>0){
            if(n&1){
                soln *= a;
            }
            n >>= 1;
            a = a*a;
        }
        if(neg) return 1.0/soln;
        return soln;
    }
};