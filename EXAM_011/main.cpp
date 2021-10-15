#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(const vector<ListNode*>& lists) {

    int k = lists.size();
    if(k == 0)
        return nullptr;

    int i;

    vector<ListNode*> IListCurrentPOS;
    IListCurrentPOS = lists;

    ListNode* result;
    ListNode* firstRES;
    firstRES = result = nullptr;

    int listofmin = -1;
    ListNode* currMin = nullptr;

    while(true){
        for(i=0;i<k;i++){
            if(currMin == nullptr){
                currMin = IListCurrentPOS[i];
                if(currMin != nullptr)
                    listofmin = i;
                continue;
            }
            if(IListCurrentPOS[i] == nullptr)
                continue;
            if(currMin->val > IListCurrentPOS[i]->val){
                currMin = IListCurrentPOS[i];
                listofmin = i;
            }
        }
        if(currMin == nullptr)
            break;

        if(firstRES == nullptr){
            firstRES = new ListNode(currMin->val);
            result = firstRES;
        }
        else{
            result->next = new ListNode(currMin->val);
            result = result->next;
        }
        IListCurrentPOS[listofmin] = currMin->next;

        currMin = nullptr;
    }
    return firstRES;
}



int main()
{


    return 0;
}
//----------------------------------------
