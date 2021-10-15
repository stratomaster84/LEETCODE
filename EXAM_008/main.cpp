#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <stack>
#include "myprofile.h"

using namespace std;

class MyNode{
public:
    int value;

    MyNode* parent;
    MyNode* left;
    MyNode* right;
};

MyNode* addValue(int value, MyNode* tree, MyNode* parent = nullptr){
    if(tree == nullptr){
        tree = new MyNode;
        tree->value = value;
        tree->left = nullptr;
        tree->right = nullptr;
        tree->parent = parent;
    }
    else if(value < tree->value){
        // left
        tree->left = addValue(value,tree->left,tree);
    }
    else if(value > tree->value){
        // right
        tree->right = addValue(value,tree->right,tree);
    }
    return tree;
}

MyNode* freeTree(MyNode* tree){
    if(tree != nullptr){
        tree->left = freeTree(tree->left);
        tree->right = freeTree(tree->right);
        delete tree;
        tree = nullptr;
    }
    return tree;
}

void printNode(MyNode* tree){
    if(tree != nullptr){
        cout << tree->value << '\n';
    }
    else
        cout << "Nothing to print" << "\n";
}

void printTree(MyNode *tree){
    if(tree != nullptr){
        printTree(tree->left);
        printNode(tree);
        printTree(tree->right);
    }
}

void levelPrint(MyNode* tree) {
    if (tree == nullptr)
    {
       return;
    }
    queue<MyNode*> q; // Создаем очередь
    q.push(tree); // Вставляем корень в очередь

    while (!q.empty() ) // пока очередь не пуста
    {
        MyNode* temp = q.front(); // Берем первый элемент в очереди
        q.pop();  // Удаляем первый элемент в очереди
        printNode(temp);

        if ( temp->left != nullptr )
            q.push(temp->left);  // Вставляем  в очередь левого потомка

        if ( temp->right != nullptr )
            q.push(temp->right);  // Вставляем  в очередь правого потомка
   }
}
void stackPrint(MyNode* tree) {
    if (tree == nullptr)
    {
       return;
    }
    stack<MyNode*> q; // Создаем стек
    q.push(tree); // Вставляем корень в стек
    while (!q.empty() ) // пока стек не пуст
    {
        MyNode* temp = q.top(); // Берем последний элемент в стеке
        q.pop();  // Удаляем последний элемент в стеке
        printNode(temp);

        if ( temp->right != nullptr )
            q.push(temp->right);  // Вставляем  в стек правого потомка

        if ( temp->left != nullptr )
            q.push(temp->left);  // Вставляем  в стек левого потомка
   }


}

MyNode* findValue(int value, MyNode *tree){
    while((tree!= nullptr) && tree->value != value){
        if(value < tree->value){
            tree = tree->left;
        }
        else{
            tree = tree->right;
        }
    }
    return tree;
}

void findAndPrintNode(int value, MyNode *tree){
    tree = findValue(value,tree);
    if(tree == nullptr)
        cout << "ERROR: no value in structure" << '\n';
    else{
        cout << "I get value: ";
        printNode(tree);
    }
}

MyNode* findAndDeleteNode(int value, MyNode* tree){
    MyNode* result = tree;
    tree = findValue(value,tree);
    if(tree == nullptr)
        cout << "ERROR: no value in structure" << '\n';
    else{
        if(tree->left == nullptr && tree->right == nullptr){
            cout << "first" << endl;
            if(tree->parent == nullptr)
                result = nullptr;
            else if(tree->parent->left == tree)
                tree->parent->left = nullptr;
            else
                tree->parent->right = nullptr;
            tree = freeTree(tree);
        }
        else if(tree->right == nullptr){
            cout << "second" << endl;
            MyNode* treetmp = tree->left;
            treetmp->parent = tree->parent;
            if(tree->parent == nullptr)
                result = treetmp;
            else if(tree->parent->left == tree)
                tree->parent->left = treetmp;
            else
                tree->parent->right = treetmp;

            delete tree;
            tree = treetmp;
        }
        else{
            cout << "third" << endl;
            MyNode* treetmp = tree->right;
            while(treetmp->left != nullptr)
                treetmp = treetmp->left;
            tree->value = move(treetmp->value);

            if(treetmp->right == nullptr){
                if(treetmp->parent->left == treetmp)
                    treetmp->parent->left = nullptr;
                else
                    treetmp->parent->right = nullptr;
                treetmp = freeTree(treetmp);
            }
            else{
                treetmp->parent->left = treetmp->right;
                delete treetmp;
            }
        }
    }
    return result;
}


int main()
{
    vector<int> vec = {121,2,1000,6,0,4, -3,5,76,92,3,8};
    MyNode *tree;
    tree = nullptr;

    for(auto i:vec){
        tree = addValue(i,tree);
    }

    printTree(tree);
    cout << '\n';
    stackPrint(tree);
    cout << '\n';
    levelPrint(tree);
    cout << '\n';

    /*for(auto i : vec){
        findAndPrintNode(i,tree);
    }*/
    for(auto i : vec){
        tree = findAndDeleteNode(i,tree);
        cout << "after delete " << i << ":\n";
        levelPrint(tree);
        cout << '\n';
    }

    //findAndDeleteNode(-3,tree);
    //tree = findAndDeleteNode(2,tree);
    //tree = findAndDeleteNode(121,tree);

    printTree(tree);

    tree = freeTree(tree);

    return 0;
}
//----------------------------------------
