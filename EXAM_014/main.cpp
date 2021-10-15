#include <iostream>
#include "myprofile.h"

using namespace std;

bool isFirstCharMatched(const char ch, const string& s, size_t sf){
    // s.size must be >=1
    if(ch == '.')
        return true;
    else if(s[sf] == ch)
        return true;
    return false;
}
bool isCountOfCharMatched(const char ch, const string& s, size_t sf, size_t count){
    // count > =1
    size_t last = sf + count;

    size_t i = sf;

    for(;i < last;++i)
        if(s[i] != ch)
            return false;
    return true;
}

bool isMatch(const string& s, const string& p, size_t sf = 0, size_t pf = 0){
    size_t sSize = s.size();
    size_t pSize = p.size();
    size_t slen = sSize - sf;       //
    size_t plen = pSize - pf;
    if(plen == 0){
        return (slen==0)?true:false;
    }

    char curr_char;
    bool char_match;
    bool result;
    curr_char = p[pf];

    if(plen == 1){
        if(slen == 0 || slen > 1)
            return false;
        return isFirstCharMatched(curr_char,s,sf);
    }

    if(p[pf+1] != '*'){
        if(slen == 0)
            return false;
        char_match = isFirstCharMatched(curr_char,s,sf);
        if(!char_match)
            return false;
        return isMatch(s,p,sf+1,pf+1);
    }
// we have only "a*" ... "z*" and ".*" with zero repeat
    result = isMatch(s,p,sf,pf+2);
    if(result == true)
        return true;

// we have only "a*" ... "z*"
    if(curr_char != '.'){
        for(size_t i=1;i<=slen;++i){
            if(isCountOfCharMatched(curr_char,s,sf,i)){
                result = isMatch(s,p,sf+i,pf+2);
            }
            if(result == true)
                return true;
        }
        return false;
    }
// we have only ".*" so all is valid
    for(size_t i=1;i<=slen;++i){
        if(isMatch(s,p,sf+i,pf+2))
            return true;
    }
    return false;
}

int main()
{
    bool g = isMatch("dtghadfdgext",".*a.*ext");
    cout << boolalpha << g;
    
    return 0;
}
//----------------------------------------
