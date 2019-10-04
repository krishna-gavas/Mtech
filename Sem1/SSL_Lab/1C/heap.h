
#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"
using namespace std;

int isEmptyHeap(Waiting* A);

Waiting* IncreaseKey(Waiting* A,int heapsize,string sname,int p);

Waiting* HeapInsert(Waiting* A,string sname,int p);

Waiting* deQueue(Waiting* header);

Waiting* MaxHeapify(Waiting* A,int i);

string ExtractMax(Waiting* A);

string returnName(Waiting* A,int i);

Waiting* deleteKey(Waiting* A,int i);

#endif