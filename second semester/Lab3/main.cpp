#include <iostream>
#include "Stack.h"
using namespace std;


void checkExpression(string, Stack &);
int main(){
    int numTest;
    int sizeOfStack;
    string arithExpr;

    cin >> sizeOfStack;
    cin >> numTest;
    Stack exprStack(sizeOfStack);
    for (int i = 0; i < numTest; ++i){
        cin >> arithExpr;
        checkExpression(arithExpr, exprStack);
        exprStack.reset();
    }
    return 0;
}
void checkExpression(string arithExpr, Stack &exprStack){
    int a = 0;
    while(a != arithExpr.length())
    {
        if (arithExpr[a] == '(')
            exprStack.push('(');
        if (exprStack.full()){return;}
        else if (arithExpr[a] == ')'){
            if (exprStack.empty()){
                cout << "More )'s" << endl;
                return;
            }
            else
                exprStack.pop();
        }
        a++;
    }
    if (!exprStack.empty()){
        cout << "More ('s" << endl;
        return;
    }
    else{
        cout << "correct\n";
        return;
    }
}
/*
4
9
2*32*5+7
6+((((20+2)*5)+2)*6)+7)
6+((((20+2)*5)+2)*6+7
(12+3*30)+(20)
6+(((((20+2)*5)+2)*6)+7)
2*5(7+23)4()
(4+(2*5(7+23))*5
(2+3)
)2+3(
*/
