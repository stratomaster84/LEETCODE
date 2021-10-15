#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// .....................ВЫВОД ВЕКТОРА
template <typename T>
void PrintVector(const vector<T>& vec, string delimeter){
    bool _isFirst = true;
    for(const auto& i : vec){
        if(_isFirst){
            cout << i;
            _isFirst = false;
            continue;
        }
        cout << delimeter << i;
    }
}
// ....................КОНЕЦ ВЫВОДА ВЕКТОРА

// ....................Реализация пары итераторов
template <typename T>
struct VecRange{
    typename vector<T>::iterator first, second;
    typename vector<T>::iterator begin() const {return first;}
    typename vector<T>::iterator end() const {return second;}
};

template <typename T>
VecRange<T> GetVecRange(vector<T>& val, size_t low, size_t top){
    if(low == 0)
        low = 1;
    low--;
    if(top < low)
        return {};
    return {  next(val.begin(),min(low,val.size())),
              next(val.begin(),min(top,val.size()))};
}
// ...................Конец реализации пары итераторов

int main()
{
    vector<string> v = {"Alexey","Natalya","Anna","Maxim","Matvey", "Pukhlya"};
    string delim = " - ";

    cout << "Vector v:" << endl;
    PrintVector(v,delim);
    cout << endl;

// Задача проитерироваться range-based "from low to top" включительно и нумерация с "1"
    vector<string> result,rest;
    size_t low=0,top=0;
    cin>>low;
    cin>>top;

    VecRange<string> _MIDRANGE = GetVecRange(v,low,top);
    VecRange<string> _FRONTRANGE = {v.begin(),_MIDRANGE.begin()};
    VecRange<string> _BACKRANGE = {_MIDRANGE.end(),v.end()};

    for(auto& s : _MIDRANGE){
        result.push_back(s);
    }
    for(auto& s : _FRONTRANGE){
        rest.push_back(s);
    }
    for(auto& s : _BACKRANGE){
        rest.push_back(s);
    }
// Конец задачи

    cout << "Vector result:" << endl;
    PrintVector(result,delim);
    cout << endl;
    cout << "Vector rest:" << endl;
    PrintVector(rest,delim);
    cout << endl;
    cout << "Program finished!!!";
    return 0;
}
