#include <iostream>
#include "myprofile.h"

using namespace std;

string intToRoman(int num)
{
    string result = "";

    int k = num/1000;
    result = string(k,'M');

    num %= 1000;
    k = num/100;
    if(k == 9)
        result += "CM";
    else if(k>=5)
        result += "D" + string(k-5,'C');
    else if(k==4)
        result += "CD";
    else
        result += string(k,'C');

    num %= 100;
    k = num/10;
    if(k == 9)
        result += "XC";
    else if(k>=5)
        result += "L" + string(k-5,'X');
    else if(k==4)
        result += "XL";
    else
        result += string(k,'X');

    num %= 10;
    if(num == 9)
        result += "IX";
    else if(num>=5)
        result += "V" + string(num-5,'I');
    else if(num==4)
        result += "IV";
    else
        result += string(num,'I');

    return result;
}

int main()
{
    cout << intToRoman(3999);

    return 0;
}
//----------------------------------------
