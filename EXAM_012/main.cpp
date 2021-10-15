#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

struct Point{
    int x;
    int y;
};
inline int myabs(int a){
    return a<0?(-a):a;
}
int getlen(const Point a, const Point b){
    return myabs(a.x - b.x) + myabs(a.y - b.y);
}
int getmin(const vector<Point> &cities, const int maxlen, const int fc, const int sc){
    int result = -1;

    int _size = cities.size();
    vector<int> nodes(_size,-1);
    queue<int> myq;
    nodes[fc] = 0;
    myq.push(fc);
    while(!myq.empty()){
        int _tmp;
        _tmp = myq.front();
        myq.pop();

        for(int i=0;i<_size;i++){
            if(_tmp == i)
                continue;
            if(nodes[i] != -1)
                continue;
            if(getlen(cities[i],cities[_tmp])>maxlen)
                continue;
            nodes[i] = nodes[_tmp]+1;
            if(i == sc){
                // найдена точка
                result = nodes[i];
                break;
            }
            myq.push(i);
        }
        if(result != -1)
            while(!myq.empty()) myq.pop();
    }
    return result;
}
int main()
{
    ifstream inp("input.txt");
    int i;

    int n;
    vector<Point> cities;
    int maxlen;
    int fc;
    int sc;

    inp >> n;

    for(i=0;i<n;i++){
        Point city;
        inp >> city.x;
        inp >> city.y;
        cities.push_back(city);
    }
    inp >> maxlen;
    inp >> fc;
    inp >> sc;
    inp.close();

    int result;
    if(fc == sc)
        result = 0;
    else
        result = getmin(cities, maxlen,fc-1,sc-1);

    ofstream outp("output.txt");
    outp << result;
    outp.close();

    return 0;
}
