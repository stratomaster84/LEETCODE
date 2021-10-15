#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct Point{
    int x;
    int y;
};
bool operator==(const Point& a, const Point& b){
    return (a.x == b.x) && (a.y == b.y);
}
inline int myabs(int a){
    return a<0?(-a):a;
}
int getlen(const Point a, const Point b){
    return myabs(a.x - b.x) + myabs(a.y - b.y);
}

int getmin(const vector<Point> &cities, const Point a, const Point b, const int maxlen){
    if(getlen(a,b) <= maxlen)
        return 1;
    if(cities.empty())
        return -1;
    int minroad = -1;
    for(auto p : cities){
        if(getlen(a,p) > maxlen)
            continue;
        vector<Point> newcities;
        newcities = cities;
        auto it = find(newcities.begin(),newcities.end(),p);
        newcities.erase(it);
        int factor = getmin(newcities,p,b,maxlen);
        if(factor == -1)
            continue;
        if(minroad == -1){
            minroad = 1 + factor;
            continue;
        }
        if(minroad > (factor+1)){
            minroad = factor+1;
        }
    }
    return minroad;
}

int main()
{
    ifstream inp("input.txt");
    int i;

    int n;
    vector<Point> cities;
    Point firstCity;
    Point secondCity;
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

    firstCity = cities[fc-1];
    secondCity = cities[sc-1];

    auto it = find(cities.begin(),cities.end(),firstCity);
    cities.erase(it);
    it = find(cities.begin(),cities.end(),secondCity);
    cities.erase(it);

    int result = getmin(cities,firstCity,secondCity,maxlen);

    ofstream outp("output.txt");
    outp << result;
    outp.close();

    return 0;
}
//----------------------------------------
