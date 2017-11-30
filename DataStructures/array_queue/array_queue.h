#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

int enqueue(int * queue,int max, int* rear,int *front,int data);
int dequeue(int * queue, int max,int *rear, int* front);
void print(int * queue,int rear, int front);

#endif
