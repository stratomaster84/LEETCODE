#include <iostream>
#include "myprofile.h"

using namespace std;

int STRToINT(const string& str){
    int num = 0;
    size_t Ssize = str.size();
    if(str[0] == 'x'){
        for(size_t pos = 1;pos<Ssize;pos++){
            num *= 16;
            if(str[pos]>='a')
                num += (str[pos]- 'a') + 10;
            else
                num += (str[pos]- '0');
        }
    }
    else if(str[0] == 'o'){
        for(size_t pos = 1;pos<Ssize;pos++){
            num *= 8;
            num += (str[pos]- '0');
        }

    }
    else if(str[0] == 'b'){
        for(size_t pos = 1;pos<Ssize;pos++){
            if(str[pos]=='1')
                num += 0b1<<(Ssize-pos-1);
        }
    }
    else{
        for(size_t pos = 0;pos<Ssize;pos++){
            num *= 10;
            num += (str[pos]- '0');
        }
    }
    return num;
}


string strToRoman(const string& str)
{
    int num=STRToINT(str);

    if(num > 3999)
        return string("ERROR: MORE THAN 3999");

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
    string str = "xabc";

    cout << str << " = " << strToRoman(str) << '\n';

    return 0;
}
//----------------------------------------
