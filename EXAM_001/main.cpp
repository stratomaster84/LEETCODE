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
template <typename Iter>
struct ItRange{
    Iter first, second;
    Iter begin() const {return first;}
    Iter end() const {return second;}
};

template <typename T>
ItRange<typename vector<T>::iterator> Range(vector<T>& val, size_t low, size_t top){
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

    PrintVector(v,delim);
    cout << endl;

// Задача проитерироваться range-based "from low to top" включительно и нумерация с "1"
    vector<string> result;
    size_t low=0,top=0;
    cin>>low;
    cin>>top;

    auto _ITRANGE = Range(v,low,top);
    for(auto& s : _ITRANGE){
        if(s[0] == 'M')
            s = "mudlo";
        result.push_back(s);
    }
// Конец задачи

    PrintVector(result,delim);
    cout << endl;
    cout << "Program finished!!!";
    return 0;
}
