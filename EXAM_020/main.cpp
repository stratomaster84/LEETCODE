#include <iostream>
#include "myprofile.h"

using namespace std;

string multiply(string num1, string num2){
    if(num1 == "0" || num2 == "0")
        return string("0");
    if(num1 == "1")
        return num2;
    if(num2 == "1")
        return num1;
// закончены крайние случаи
    size_t snum1 = num1.size();
    size_t snum2 = num2.size();
    string result(snum1+snum2,'0');

    size_t i,j;
    uint8_t chars_mul;

    for(j = snum2;j--;){
        chars_mul = 0;
        for(i = snum1;i--;){
            chars_mul += (num2[j]-'0')*(num1[i]-'0') + (result[i+j+1]-'0');
            result[i+j+1] = (chars_mul%10) + '0';
            chars_mul /= 10;
        }
        result[i+j+1] = (chars_mul%10) + '0';
    }
    if(result[0] == '0')
        result.erase(result.begin());
    return result;
}

int main()
{
    cout << multiply("4294967296","4294967296");
    return 0;
}
//----------------------------------------
