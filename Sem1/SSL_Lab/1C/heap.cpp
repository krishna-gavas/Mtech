#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include "list.h"
#include "heap.h"

using namespace std;

int heapsize=0;

int isEmptyHeap(Waiting* A){
    if(heapsize == 0)
        return 1;
    else 
        return 0;
}


Waiting* IncreaseKey(Waiting* A,int i,string sname,int p){
    if(p < A[i].priority){
        cout<<"new key is smaller than current key"<<endl;
        return A;
    }
    A[i].name = sname;
    A[i].priority = p;
    while(i > 1 && A[i/2].priority < A[i].priority){
        int temp1 = A[i/2].priority;
        A[i/2].priority = A[i].priority;
        A[i].priority = temp1;

        string temp2 = A[i/2].name;
        A[i/2].name = A[i].name;
        A[i].name = temp2;

        i = i/2;
    }

    return A;
}

Waiting* HeapInsert(Waiting* A,string sname,int p){
    heapsize = heapsize + 1;
    A[heapsize].name = "";
    A[heapsize].priority = -1;
    
    A = IncreaseKey(A,heapsize,sname,p);

    return A;
}


Waiting* MaxHeapify(Waiting* A,int i){
    int l = 2*i;
    int r = 2*i + 1;
    int largest;
    if(l <= heapsize && A[l].priority > A[i].priority)
        largest = l;
    else
        largest = i;

    if(r <= heapsize && A[r].priority > A[largest].priority)
        largest = r;

    if(largest != i){
        int temp1 = A[largest].priority;
        A[largest].priority = A[i].priority;
        A[i].priority = temp1;

        string temp2 = A[largest].name;
        A[largest].name = A[i].name;
        A[i].name = temp2;

        A = MaxHeapify(A,largest);
    }
    return A;
}

string ExtractMax(Waiting* A){
    if(heapsize < 1)
        cout<<"Heap Underflow"<<endl;

    string max = A[1].name;
    A[1] = A[heapsize];
    A[heapsize].name = "";
    A[heapsize].priority = 0;
    heapsize = heapsize - 1;
    A = MaxHeapify(A,1);

    return max;

}

string returnName(Waiting* A,int i){
    string sname;
    sname = A[i].name;
    return sname;
}

Waiting* deleteKey(Waiting* A,int i){
    if(heapsize < 1)
        cout<<"Heap Underflow"<<endl;

    A[i].priority = A[heapsize].priority;
    A[i].name = A[heapsize].name;

    A[heapsize].name = "";
    A[heapsize].priority = 0;
    heapsize = heapsize - 1;
    A = MaxHeapify(A,i);

    return A;
}