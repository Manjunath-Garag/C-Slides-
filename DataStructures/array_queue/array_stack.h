#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

 void push(int data, int max, int *top, int *stack); //top is Pass by REfrence.
 int pop(int *top, int *stack);  //top is Pass by Refrence. The change in the Top will be reflected in the main function.
 void peep(int top, int *stack); //top is pass by Value. beacuse we should not change the value of top  by passing by PASS-BY-REF
 void peek(int top, int *stack);  //top is Pass by Value, because we are not supposed to change the value of top.

#endif
