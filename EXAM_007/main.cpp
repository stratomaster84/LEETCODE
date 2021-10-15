#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> summ(const vector<T> &first, const vector<T> &last){
    size_t fsz = first.size();
    size_t lsz = last.size();
    vector<T> result;
    result.reserve(fsz+lsz);
    size_t i;
    for(i=0;i<fsz;i++)
        result.push_back(first[i]);
    for(i=0;i<lsz;i++)
        result.push_back(last[i]);
    return result;
}

template <typename T>
vector<vector<T>> getRes(const vector<T> &first, const vector<T> &_main ){
    size_t sz = _main.size();
    vector<vector<T>> result;
    vector<T> tmp,tmp2;
    if(sz == 1){
        tmp = summ(first,_main);
        result.push_back(tmp);
        return result;
    }
    size_t i;
    for(i=0;i<sz;i++){
        tmp = first;
        tmp.push_back(_main[i]);
        tmp2 = _main;
        tmp2.erase(tmp2.begin()+i);
        result = summ(result,getRes(tmp,tmp2));
    }
    return result;
}

template <typename T>
void printVec(vector<vector<T>> vec){
    for(size_t i=0;i<vec.size();i++){
        for(size_t j=0;j<vec[i].size();j++)
            cout << vec[i][j] << ' ';
        cout << '\n';
    }
}
int main()
{
    vector<int> v = {1,2,3};

    vector<decltype (v)> res;
    res = getRes(decltype (v)(),v);
    printVec(res);
    return 0;
}
//----------------------------------------
