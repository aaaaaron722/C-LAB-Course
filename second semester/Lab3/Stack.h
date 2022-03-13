#ifndef Stack_H
#define Stack_H
class Stack
{
    private:
        int stackSize;
        int stackPtr; // index of top element
        char *charStack;
    public:
        Stack(int);
        void push(char);
        char pop();
        void reset();
        bool empty();
        bool full();

};
#endif
