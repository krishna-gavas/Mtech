
#ifndef LIST_H
#define LIST_H

using namespace std;


struct Student{
    string name;
    Student* next;
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


struct Student* Insert(Student* header,string sname);

struct Student* Delete(Student* header,string sname);

#endif