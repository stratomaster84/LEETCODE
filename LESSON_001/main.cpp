#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList(ListNode* list){
    stack<int> nodes;
    ListNode* tmp = list;

    if(tmp == nullptr){
        cout << "ERROR: List is empty";
        return;
    }
    while(tmp != nullptr){
        nodes.push(tmp->val);
        tmp = tmp->next;
    }
    while(!nodes.empty()){
        cout << nodes.top();
        nodes.pop();
    }
}

ListNode* IntToList(int x){
    stack<int> nodes;
    ListNode* result = nullptr;

    while(x != 0){
        nodes.push(x % 10);
        x /= 10;
    }
    while(!nodes.empty()){

        if(nodes.size() == 0)
            result = new ListNode(nodes.top());
        else
            result = new ListNode(nodes.top() , result);
        nodes.pop();
    }

    return result;
}

int ListToInt(ListNode *list){
    int result=0;
    stack<int> nodes;
    ListNode *tmp = list;

    if(list == nullptr)
        return 0;

    while(tmp != nullptr){
        nodes.push(tmp->val);
        tmp = tmp->next;
    }
    while(!nodes.empty()){
        result = result*10 + nodes.top();
        nodes.pop();
    }
    return result;
}

int main()
{
// ИНИЦИАЛИЗАЦИЯ ПЕРЕМЕННЫХ
    char operation = '+';
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    int x1=0;
    int x2=0;
    int y=0;
    ListNode *result = nullptr;
// ~ИНИЦИАЛИЗАЦИЯ ПЕРЕМЕННЫХ

// ПОДГОТОВКА ЛИСТОВ
    {
        int enter1=0;
        int enter2=0;
        cin >> enter1 >> operation >> enter2;
        l1 = IntToList(enter1);
        l2 = IntToList(enter2);
    }
// ~ПОДГОТОВКА ЛИСТОВ

// РАСШИФРОВКА ЛИСТОВ
    x1 = ListToInt(l1);
    x2 = ListToInt(l2);
// РАСШИФРОВКА ЛИСТОВ

// ОПЕРАЦИИ НАД ЧИСЛАМИ
    switch (operation) {
        case '+' : y = x1 + x2; break;
        case '*' : y = x1 * x2; break;
        case '^' : y = pow(x1,x2); break;
        default  : y = 0;
    }
// ~ОПЕРАЦИИ НАД ЧИСЛАМИ

// ПОДГОТОВКА РЕЗУЛЬТИРУЮЩЕГО ЛИСТА
    result = IntToList(y);
// ~ПОДГОТОВКА РЕЗУЛЬТИРУЮЩЕГО ЛИСТА

// ВЫВОД РЕЗУЛЬТАТА
    cout << endl;
    PrintList(l1);
    cout << ' ' << operation << ' ';
    PrintList(l2);
    cout << " = ";
    PrintList(result);
    cout << endl;

    return 0;
}
