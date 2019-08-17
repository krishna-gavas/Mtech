
#ifndef LIST_H
#define LIST_H

using namespace std;


struct Student{
    string name;
    Student* left;
    Student* right;
};

struct Waiting{
    string name;
    Waiting* prev;
    Waiting* next;
};

struct Course{
	string code;
	string name;
	int credits;
    int maxLimit;
    struct Student *regList;
    struct Waiting *waitList;
};


Student* getNewNode(string data);

Student* Insert(Student* root,string sname);

Student* FindMinNode(Student* root);

Student* Delete(Student* header,string sname);

void push(Student*  Stack[],int n,Student* X);

void pop(Student*  Stack[],int n);

bool empty(Student*  Stack[],int n);

Student* Top(Student*  Stack[]);

void treeWalk(Student* root,int n);

void treeWalkDESC(Student* root,int n);

string* treeWalkN(Student* root,string* str,int n);

#endif