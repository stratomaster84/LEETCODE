#include <iostream>
#include <vector>
#include "myprofile.h"

using namespace std;

string convert(const string &s, int numRows){
    if(numRows == 1)
        return string(s);
    string res;
    int ssize = s.size();
    res.resize(ssize);
    int i = 0;
    int incr = (numRows-1)*2;
    while(i < ssize){
        int j;
        // first row
        for(j=i;j<ssize;j+=incr){
            res[i++] = s[j];
            if(i==ssize)
                break;
        }
        if(i==ssize)
            break;
        //middle rows
        for(int row = 2;row<numRows;++row){
            for(j=row-1;j<ssize;j+=incr){
                res[i++] = s[j];
                if(i==ssize)
                    break;
                if(j+(numRows-row)*2 < ssize){
                    res[i++] = s[j+(numRows-row)*2];
                    if(i==ssize)
                        break;
                }
            }
            if(i==ssize)
                break;
        }
        if(i==ssize)
            break;
        //last row
        for(j=numRows-1;j<ssize;j+=incr){
            res[i++] = s[j];
            if(i==ssize)
                break;
        }
    }
    return res;
}
string convert2(const string &s, int numRows){
    if(numRows == 1)
        return string(s);
    int ssize = s.size();
    vector<string> vec;
    vec.resize(numRows);

    int i;
    int incr = (numRows-1)*2;
    for(i=0;i<ssize;i++){
        int _mod = i%incr;
        if(_mod < numRows)
            vec[_mod].push_back(s[i]);
        else
            vec[incr-_mod].push_back(s[i]);
    }
    string res = "";
    for(auto &ss : vec){
        res += ss;
    }
    return res;
}

int main()
{
    string s = string(1000,'a');


    {
    LOG_DURATION("convert");
        for(int i=0;i<1E5;i++)
            convert(s,5);
    }
    {
    LOG_DURATION("convert2");
        for(int i=0;i<1E5;i++)
            convert(s,5);
    }

    //cout << s << '\n' << convert(s,5) << '\n' << convert2(s,5) << endl;
    return 0;
}
