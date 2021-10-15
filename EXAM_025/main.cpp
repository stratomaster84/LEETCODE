#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void gen(vector<string> &v,string current,const size_t opened,const size_t closed,const size_t n){
    if(current.size() == (n<<1)){
        v.push_back(current);
    }
    if(opened < n){
        gen(v,current + '(',opened+1,closed,n);
    }
    if(closed < opened){
        gen(v,current + ')',opened,closed+1,n);
    }
}


int main()
{

    int n;
    cin >> n;

    string result;
    vector<string> v;
    gen(v,"",0,0,n);

    return 0;
}
