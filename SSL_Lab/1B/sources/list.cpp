#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include "list.h"
#include "Queue.h"

using namespace std;

Student* Insert(Student* header,string sname){
	int flag = 0;
    struct Student* temp = new Student();
	struct Student* cur = header;
	struct Student* prev;	
    temp->name = sname;
	if(header==NULL || (cur->name.compare(temp->name)>0)){
		temp->next = header;
    	header = temp;
	}
	else{
		while(cur != NULL){
			if(cur->name.compare(temp->name)>0){
				prev->next = temp;
				temp->next = cur;
				flag = 1;
				break;
			}
			prev = cur;
			cur = cur->next;
		}
		if(flag == 0){
			prev->next = temp;
			temp->next = NULL;
		}
	}

    cout<<"Normal List: "<<endl;
	struct Student* temp1 = header;
	while(temp1 != NULL){
		cout<<temp1->name<<endl;
		temp1 = temp1->next;
	}
	cout<<endl;

    return header;
}

Student* Delete(Student* header,string sname){
	struct Student* cur = header;
	struct Student* prev;
	if(!(sname.compare(cur->name))){
		header = header->next;
		free(cur);
	}
	else{
		while(cur != NULL){
			if(!(sname.compare(cur->name))){
				prev->next = cur->next;
				free(cur);
				break;
			}
			prev = cur;
			cur = cur->next;
		}
	}
	



    return header;
}