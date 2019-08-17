#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include "list.h"
#include "Queue.h"

using namespace std;

int isEmptyQueue(Waiting* header){
    if(header == NULL)
        return 1;
    else 
        return 0;
}

string returnName(Waiting* header){
    string sname;
    struct Waiting* cur = header;
    sname = cur->name;

    return sname;
}

Waiting* enQueue(Waiting* header,string sname){
    struct Waiting* temp = new Waiting();
    struct Waiting* cur = header;
    struct Waiting* before;
    temp->name = sname;
    if(header == NULL){
        temp->prev = header;
        temp->next = NULL;
        header = temp;
    }
    else{
        while(cur != NULL){
            before = cur;
            cur = cur->next;         
        }
        before->next = temp;
        temp->prev = before;
        temp->next = NULL;

    }

    cout<<"Waiting List: "<<endl;
	struct Waiting* temp1 = header;
	while(temp1 != NULL){
		cout<<temp1->name<<endl;
		temp1 = temp1->next;
	}
	cout<<endl;

    return header;

}

Waiting* deQueue(Waiting* header){
    struct Waiting* cur = header;
    if(cur->next == NULL){
        header = header->next;
        free(cur);
    }
    else{
        header = header->next;
        header->prev = NULL;
        free(cur);
    }
    


    return header;
}