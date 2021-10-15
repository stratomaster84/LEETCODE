#include <iostream>
#include <queue>
#include <set>
#include <memory>
#include <unordered_map>

using namespace std;

//----------------------------------------
template <class T>
class ObjectPool{
public:
    T* Allocate();
    T* TryAllocate();
    void Deallocate(T* object);
    ObjectPool();
    ~ObjectPool();
private:
    queue<unique_ptr<T>> free;
    unordered_map<T*,unique_ptr<T>> allocated;
};
//----------------------------------------
template <class T>
T* ObjectPool<T>::Allocate(){
    if(free.empty()){
        free.push(make_unique<T>());
    }
    auto ptr = move(free.front());
    free.pop();
    T* ret = ptr.get();
    allocated[ret] = move(ptr);
    return ret;
}
//----------------------------------------
template <class T>
T* ObjectPool<T>::TryAllocate(){
    if(free.empty()){
        return nullptr;
    }
    return Allocate();
}
//----------------------------------------
template <class T>
void ObjectPool<T>::Deallocate(T* object){
    auto it = allocated.find(object);
    if(it == allocated.end()){
        throw invalid_argument("");
    }
    free.push(move(it->second));
    allocated.erase(it);
}
//----------------------------------------
template <class T>
ObjectPool<T>::ObjectPool(){
    cout << "OBJECTPOOL +++" << endl;
}
//----------------------------------------
template <class T>
ObjectPool<T>::~ObjectPool(){
    cout << "OBJECTPOOL ---" << endl;
}
//----------------------------------------
int counter = 0;
int _last_mine = 0;
//----------------------------------------
struct _mine{
    _mine() : _number(++_last_mine) {cout << "Mine # " << _number << " +++" << endl; counter++;}
    ~_mine(){cout << "Mine # " << _number << " ---" << endl; counter--;}
    int _number;
};
//----------------------------------------
int main()
{
    ObjectPool<_mine> MyPool;
    auto ptr1 = MyPool.Allocate();
    auto ptr2 = MyPool.Allocate();
    auto ptr3 = MyPool.Allocate();
    //MyPool.Deallocate(ptr2);
    auto ptr4 = MyPool.Allocate();
    auto ptr5 = MyPool.Allocate();

    return 0;
}
//----------------------------------------
