#include <iostream>
#include <vector>
#include <queue>
#include "myprofile.h"

using namespace std;

template<typename T>
struct node{
    T value;        // значение узла (у "class T" - должны быть определены операторы (<, >, ==, <<) и конструктор копирования)
    node* left;     // указатель на левую ветку
    node* right;    // указатель на правую ветку
    uint8_t height; // глубина дерева

    node(const T& val):    // конструктор вставки узла
        value(val),
        left(nullptr),
        right(nullptr),
        height(1)
    {}
};
// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
template<typename T>
uint8_t getheight(node<T>* p){  // возвращает глубину дерева и может работать с нулевым указателем
    return (p != nullptr) ? p->height : 0;
}
template<typename T>
int bfactor(node<T>* p){        // возвращает фактор разбалансировки дерева, т.е. разность глубин левой и правой веток
    return static_cast<int>(getheight(p->right))-static_cast<int>(getheight(p->left));
}
template<typename T>
void fixheight(node<T>* p){     // вычисляет новую глубину деврева, т.е. бОльшую из глубин его ветвей + 1
    uint8_t hl = getheight(p->left);
    uint8_t hr = getheight(p->right);
    p->height = (hl>hr?hl:hr)+1;
}
template<typename T>
node<T>* freeTree(node<T>* p){   // удаление всего дерева
    if(p != nullptr){
        p->left = freeTree(p->left);    // каскадное удаление левой ветки
        p->right = freeTree(p->right);  // ... правой ветки
        delete p;                       // удаление оставшегося листа
        p = nullptr;                    // присваиваем указателю для возврата nullptr
    }
    return p;
}
// ФУНКЦИИ ПОВОРОТА И БАЛАНСИРОВКИ
// -----ПРАВЫЙ ПОВОРОТ-----
//     p            q     |
//    / \          / \    |
//   q   C  ===>  A   p   |
//  / \              / \  |
// A   B            B   C |
//-------------------------
template<typename T>
node<T>* rotateright(node<T>* p){
    node<T>* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);   // поправляем глубину ... СНАЧАЛА "p"
    fixheight(q);   //                    ... ПОТОМ "q"
    return q;
}
// ------ЛЕВЫЙ ПОВОРОТ-----
//   q               p    |
//  / \             / \   |
// A   p    ===>   q   C  |
//    / \         / \     |
//   B   C       A   B    |
//-------------------------
template<typename T>
node<T>* rotateleft(node<T>* q)
{
    node<T>* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);   // поправляем глубину ... СНАЧАЛА "q"
    fixheight(p);   //                    ... ПОТОМ "p"
    return p;
}
// БАЛАНСИРОВКА
template<typename T>
node<T>* balance(node<T>* p){
    fixheight(p);               // поправляем глубину перед балансировкой

    if(bfactor(p) == 2){        // если правое перевешивает на 2 (больше быть не может), то нужен левый поворот - см. рисунок (p.height - A.height = 2)
        if(bfactor(p->right) < 0)               // если в дереве "p" - "B" > "C"
            p->right = rotateright(p->right);   // ,то сначала перевернём дерево "p", т.к. иначе "B" останется на той же глубине
        return rotateleft(p);                   // только потом сделаем нужный левый поворот
    }
    if(bfactor(p) == -2){       // если левое перевешивает на 2 (больше быть не может), то нужен правый поворот - см. рисунок (q.height - C.height = 2)
        if(bfactor(p->left) > 0)                // если в дереве "q" - "B" > "A"
            p->left = rotateleft(p->left);      // ,то сначала перевернём дерево "q", т.к. иначе "B" останется на той же глубине
        return rotateright(p);                  // только потом сделаем нужный правый поворот
    }
    return p; // ИНАЧЕ балансировка была и не нужна
}

// ФУНКЦИЯ ВСТАВКИ ЭЛЕМЕНТА
template<typename T>
node<T>* insert(node<T>* p, T val){
    if(p == nullptr)
        return new node(val);           // если так и не нашлось значения в дереве - создаём новый узел
    if(val < p->value)                  // если значение меньше текущего, но его ещё не нашлось...
        p->left = insert(p->left,val);  // ...идём влево
    else if(val > p->value)             // если значение больше текущего, но его ещё не нашлось...
        p->right = insert(p->right,val);// ...идём вправо
    //else ----------->                    если значение равно текущему, ничего не делаем (можно увеличивать счётчик встречаний например)
    return balance(p);                  // балансируем вновь вставленный элемент
}

// ФУНКЦИЯ НАХОЖДЕНИЯ МИНИМУМА В КОНКРЕТНОМ УЗЛЕ
template<typename T>
node<T>* findmin(node<T>* p){
    return (p->left == nullptr) ? p : findmin(p->left); // возвращаем минимальный элемент дерева "p"
}
// ФУНКЦИЯ ПЕРЕРАСПРЕДЕЛЕНИЯ ПРАВОГО ДЕРЕВА ПРИ УДАЛЕНИИ МИНИМУМА
template<typename T>
node<T>* restructmin(node<T> *p){
    if( p->left == nullptr )    // если "p" не имеет левой ветки, значит он и есть минимум, поэтому...
        return p->right;        // ...возвращаем его правый узел, для дальнейшей записи его вместо "p" извне
    p->left = restructmin(p->left); // если в "p" есть левая ветка, находим дальше
    return balance(p);  // балансируем перераспределённое дерево "p"
}
// ФУНКЦИЯ УДАЛЕНИЯ ЭЛЕМЕНТА
template<typename T>
node<T>* remove(node<T>* p, T val){
    if(p == nullptr)
        return nullptr;                 // если так и не нашлось значения в дереве - значит ничего не делаем
    if(val < p->value)                  // если значение меньше текущего, но его ещё не нашлось...
        p->left = remove(p->left,val);  // ...идём влево
    else if(val > p->value)             // если значение больше текущего, но его ещё не нашлось...
        p->right = remove(p->right,val);// ...идём вправо
    else{ //val == p->value                если значение равно текущему, то удаляем его (или уменьшаем счётчик на 1)
        node<T>* l = p->left;           // сохраняем левую ветку...
        node<T>* r = p->right;          // ... и правую
        delete p;                       // удаляем сам узел
        if(r == nullptr)                // если правой ветки нет, то...
            return l;                   // ... просто возвращаем (СТАВИМ) левую ветку на место удаляемого узла
        node<T>* min = findmin(r);      // ИНАЧЕ... находим минимальный элемент в правой ветке и сохраняем указатель на него
        min->right = restructmin(r);    // ставим в ЕГО правую ветку переструктурированную "p->right"...
        min->left = l;                  // ...а в левую - ту ветку, которая была в удаляемом "p", т.е. "p->right"
                                        // важно сделать две последние инструкции именно в таком порядке
        return balance(min);            // балансируем новую ветку и возвращаем (СТАВИМ) её на место удаляемого узла
    }
    return balance(p);                  // если не удалили - т.е. сработал...
                                        //            ..."if(val < p->value)" или "else if(val > p->value)"...
                                        // ...балансируем обновлённое дерево "p" и возвращаем его в место вызова
}

// ----------РАСПЕЧАТКИ ДЕРЕВА------------
// РАСПЕЧАТКА УЗЛА
template<typename T>
void printNode(node<T>* p){
    if(p != nullptr){
        cout << p->value << '\n';       // тут нужно, чтобы был определён operator<< для "class T"
    }
    else
        cout << "NO VALUE!!!" << '\n';
}

// РАСПЕЧАТКА ДЕРЕВА (СИММЕТРИЧНЫЙ ОБХОД В ГЛУБИНУ С РЕКУРСИЕЙ)
template<typename T>
void printTree(node<T> *p){
    if(p != nullptr){
        if(p->left != nullptr) printTree(p->left);  // печатаем рекурсивно левую ветвь
        printNode(p);                               // печатаем узел
        if(p->right != nullptr) printTree(p->right);// печатаем рекурсивно правую ветвь
    }
    else
        cout << "TREE IS EMPTY!!!" << '\n';
}

// РАСПЕЧАТКА ДЕРЕВА (ОБХОД В ШИРИНУ С ОЧЕРЕДЬЮ)
template<typename T>
void levelPrint(node<T>* p){
    if(p == nullptr){
        cout << "TREE IS EMPTY!!!" << '\n';
        return;
    }
    queue<node<T>*> _Q;                     // Создаем очередь
    _Q.push(p);                             // Вставляем (копируем) узел в очередь

    while(!_Q.empty()){                     // пока очередь не пуста
        node<T>* temp = _Q.front();         // Берем первый элемент из очереди (копируем)
        _Q.pop();                           // Удаляем первый элемент из очереди
        printNode(temp);
        if (temp->left != nullptr)
            _Q.push(temp->left);            // Вставляем в очередь узел левой ветви
        if (temp->right != nullptr)
            _Q.push(temp->right);           // Вставляем в очередь узел правой ветви
    }
}
//---------------------


int main()
{
    vector<int> vec1 = {121,2,1000,6,0,4, -3,5,76,121,3,8};
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    node<int> *tree;
    tree = nullptr;

    for(auto i:vec){
        tree = insert(tree,i);
    }

    printTree(tree);
    cout << '\n';
    levelPrint(tree);
    cout << '\n';

    /*for(auto i : vec){
        tree = remove(tree,i);
        cout << "after delete " << i << ":\n";
        levelPrint(tree);
        cout << '\n';
    }*/

    /*tree = remove(tree,121);
    tree = remove(tree,2);
    levelPrint(tree);
    cout << '\n';

    tree = insert(tree,-7);
    levelPrint(tree);
    cout << '\n';*/

    printTree(tree);

    tree = freeTree(tree);
    return 0;
}
//----------------------------------------
