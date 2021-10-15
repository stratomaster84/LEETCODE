#include <iostream>
#include <deque>
#include <boost/unordered_map.hpp>

std::vector<int> func(std::vector<int> v1,std::vector<int> v2){
    std::vector<int> res;

    std::sort(v1.begin(),v1.end());
    std::sort(v2.begin(),v2.end());

    int i=0,j=0;

    int v_size = v1.size() + v2.size();
    for(;v_size>i+j-1;){
        if(v1[i] < v2[j]){
            ++i;
        }
        else if(v1[i] > v2[j]){
            ++j;
        }
        else{
            res.push_back(v1[i]);
            ++i;
            ++j;
        }
    }
    return res;
}


int main()
{
    std::vector<int> v1 = {1,7,3,56,9,2,4,5,1};
    std::vector<int> v2 = {7,4,1,6,3,2,9,0,1};

    std::vector<int> result = func(v1,v2);

    return 0;
}
