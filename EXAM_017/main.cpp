#include <iostream>
#include "myprofile.h"

using namespace std;

int divide(int dividend, int divisor) {
    if(divisor == 0)
        return INT_MAX;
    else if(divisor == -1)
        return dividend==INT_MIN?INT_MAX:-dividend;
    else if(divisor == 1 || dividend == 0) // not must be... but
        return dividend;

    bool negative;
    uint32_t u_d_end;
    uint32_t u_d_sor;
    if(dividend == INT_MIN){
        negative = true;
        u_d_end = 0x80000000;
    }
    else if(dividend < 0){
        negative = true;
        u_d_end = -dividend;
    }
    else{
        negative = false;
        u_d_end = dividend;
    }
    if(divisor == INT_MIN){
        negative = !negative;
        u_d_sor = 0x80000000;
    }
    else if(divisor < 0){
        negative = !negative;
        u_d_sor = -divisor;
    }
    else
        u_d_sor = divisor;
    if(u_d_end < u_d_sor)
        return 0;

    uint32_t res = 0;
    uint32_t tmp1, tmp2;
// деление в столбик в двоичном счислении
// + кол-во бит в "a"
    tmp1 = u_d_end;
    tmp2 = 0;
    while(tmp1){
        tmp1 >>= 1;
        tmp2++;
    }
// - кол-во бит в "b"
    tmp1 = u_d_sor;
    while(tmp1){
        tmp1 >>= 1;
        tmp2--;
    }
//
    tmp1 = u_d_sor;
    tmp1 <<= tmp2;
//
    tmp2++;
    while(tmp2--){
        res <<= 1;
        if(tmp1 <= u_d_end){
            u_d_end -= tmp1;
            res++;
        }
        tmp1 >>= 1;
    }
    return negative?-res:res;
}

int main()
{
    cout << divide(-58232354,7635) << '\n';
    cout << unsigned(INT_MIN);

    return 0;
}
//----------------------------------------
