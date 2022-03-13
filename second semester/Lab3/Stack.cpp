#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack(int sizeOfStack){
    stackSize = sizeOfStack;
    stackPtr = 0;
    charStack = new char[stackSize];
}
void Stack::push(char x){
    if (full()){return;}
    charStack[++stackPtr] = x;
}
char Stack::pop(){ //return the topmost element from a stack
    if(empty()){;}
    stackPtr--;
    return charStack[stackPtr];
}
void Stack::reset(){
    delete charStack;
    charStack = new char[stackSize];
    stackPtr = 0;
}
bool Stack::empty(){
    return (stackPtr == 0);// if true return true
}
bool Stack::full(){
    if (stackPtr > stackSize){
        cout << "stack full" << endl;
        return true;
    }
    else
        return false;
}
