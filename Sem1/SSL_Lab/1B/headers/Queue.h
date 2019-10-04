
#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"
using namespace std;

int isEmptyQueue(Waiting* header);

string returnName(Waiting* header);

Waiting* enQueue(Waiting* header,string sname);

Waiting* deQueue(Waiting* header);


#endif