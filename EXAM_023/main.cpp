#include <iostream>
#include <vector>
#include "myprofile.h"

using namespace std;

double myPow(double x, int n) {
    if(x == 0.0){
        if(n>0)
            return x;
        else if(n<0)
            return INT_MAX; // ???????????????
        else
            return 1; // ??????????????????
    }
    if(n == 0)
        return 1.0;
    if(n == 1)
        return x;
    if(x == 1.0)
        return x;
// end of edge cases
    bool n_is_INT_MIN = false;
    bool n_is_neg;
    if(n == INT_MIN){
        n_is_INT_MIN = true;
        n = INT_MAX;
    }
    else if(n<0){
        n_is_neg = true;
        n = -n;
    }
    else{
        n_is_neg = false;
    }
// now we got x^(n >= 2)
    double _mul = x;
    double result = 1;
    while(n!=0){
        if(n&0b1)
            result *= _mul;
        _mul *=_mul;
        n >>= 1;
    }
    if(n_is_INT_MIN)
        return 1.0/result/x;
    return n_is_neg?(1.0/result):result;
}

int main()
{
    cout << myPow(0.999999999,-2147483648);
    return 0;
}
//----------------------------------------
