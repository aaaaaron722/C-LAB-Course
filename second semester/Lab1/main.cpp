#include <iostream>
using namespace std;

struct NODE{ //struct
    int data;
    NODE *link;
};

void createList(NODE *&head);
void deleteEle(NODE *&head);
bool searchLinkList(NODE *head, int target, NODE *&prePtr, NODE *&curPtr);
void insertLinkedList(NODE *&head, int data);
void deleteLinkedList(NODE *&head, int data);
void displayList(NODE *head);
void freeList(NODE *headPtr);

int main(){
    int numTests;
    cin >> numTests;
    for (int i = 0; i < numTests; i++){
        NODE *listHead = NULL;
        // first part
        createList(listHead);
        displayList(listHead);
        // second part
        deleteEle(listHead);
        displayList(listHead);
        freeList(listHead);
    }
    return 0;
}

void createList(NODE *&head){
    int preNum = 1; // previous number
    int curNum; // current number
    while (cin >> curNum){
        if (preNum == 0 && curNum == 0){break;}
        preNum = curNum;
        insertLinkedList(head, curNum);
    }
}
void deleteEle(NODE *&head){
    int preNum = 1;
    int curNum;
    while (cin >> curNum){
        if (preNum == 0 && curNum == 0){break;}
        preNum = curNum;
        deleteLinkedList(head, curNum);
    }
}
bool searchLinkList(NODE *head, int target, NODE *&prePtr, NODE *&curPtr){
    prePtr = NULL;
    curPtr = head;
    while (curPtr != NULL && target < curPtr->data){ // if cur is not NULL and the target > exist node
        prePtr = curPtr; // pre point to cur 
        curPtr = curPtr->link; // cur point link to next node
    }
    if (curPtr != NULL && target == curPtr->data){
        return true; // if true means there is a exist target
    }
    else{
        return false;
    }
}
void insertLinkedList(NODE *&head, int data){
    NODE *curPtr;
    NODE *prePtr;
    NODE *newNode = new NODE;
    newNode->data = data;
    newNode->link = NULL;
    if (searchLinkList(head, data, prePtr, curPtr)) // if true means do not insert.
        return;
    if (head == NULL){
        head = newNode;
        return;
    }
    // at the beginning
    if (prePtr == NULL){
        newNode->link = curPtr;
        head = newNode;
        curPtr = newNode;
        return;
    }
    // at the end
    if (curPtr == NULL){
        prePtr->link = newNode;
        newNode->link = NULL;
        prePtr = newNode;
        return;
    }
    // at the middle
    newNode->link = curPtr;
    prePtr->link = newNode;
    prePtr = newNode;
    return;
}
void deleteLinkedList(NODE *&head, int data){
    NODE *prePtr = head;
    NODE *curPtr = NULL;
    if (!searchLinkList(head, data, prePtr, curPtr)) // not found so it does not delete
        return; 
    if (prePtr == NULL){ // delete at the beginning
        head = curPtr->link;
    } 
    else{ // delete at the middle or the end
        prePtr->link = curPtr->link;
    }
    curPtr->link = NULL;
    delete curPtr;
    
}
void displayList(NODE *listHead){
    int count = 0;
    NODE *curPtr = listHead;
    cout << "# ";
    while (curPtr != NULL){
        if (count % 15 == 0 && count != 0){
            cout << endl << "# ";
        }
        cout << curPtr->data << " ";
        curPtr = curPtr->link;
        count++;
    }
    cout << endl;
    cout << "# Total number of elements in the linked list: " << count << endl;
}
void freeList(NODE *headPtr){
    NODE *tempPtr;
    while (headPtr != NULL){
        tempPtr = headPtr;
        headPtr = headPtr->link;
        tempPtr->link = NULL;
        delete tempPtr;
    }
}
/*
3
120 -1 113 65 -43 0 23 44 8 65 -1 0 0
65 65 -1 43 44 2 0 0

7 9 -5 8 8 -5 0 10 0 0
10 9 10 7 0 6 0 0 

1 2 3 4 5 6 7 8 9 10 17 16 16 15 14 11 13 12 0 10 0 0
0 1 2 3 4 5 5 5 6 6 7 8 9 10 11 12 13 15 14 16 17 18 0 0
*/
