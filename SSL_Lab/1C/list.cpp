#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include "list.h"
#include "heap.h"

using namespace std;

int i = 0,top = -1;

Student* getNewNode(string data){
    Student* newNode = new Student();
    newNode->name = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Student *Insert(Student *root, string sname)
{
	if(root == NULL)
        root = getNewNode(sname);
    //else if(sname <= root->name)
	else if(sname.compare(root->name) <= 0)
        root->left = Insert(root->left,sname);
    else
        root->right = Insert(root->right,sname);

    return root;
}

Student* FindMinNode(Student* root){
    if(root == NULL){
        cout<<"Error: Tree is empty"<<endl;
        return root;
    }

    while(root->left != NULL)
        root = root->left;

    return root;
    
}

Student *Delete(Student *root, string sname)
{
	if(root == NULL)
        return root;
    // else if(sname < root->name)
	else if(sname.compare(root->name) < 0)
        root->left = Delete(root->left,sname);
    else if(sname.compare(root->name) > 0)
        root->right = Delete(root->right,sname);
    else{
        //case1: No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        //case2: 1 child
        else if(root->left == NULL){
            struct Student* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            struct Student* temp = root;
            root = root->left;
            free(temp);
        }
        //case3: 2 children
        else{
            struct Student* temp = FindMinNode(root->right);
            root->name = temp->name;
            root->right = Delete(root->right,temp->name);
        }
    }
    return root;
}

//------------------------------STACK OPERATIONS ------------------------------

void push(Student*  Stack[],int n,Student* X){
	if(top == n-1){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	Stack[++top] = X;
}

void pop(Student*  Stack[],int n){
	if(top == -1){
		cout<<"Stack Underflow"<<endl;
		return;
	}
	top--;
}

bool empty(Student*  Stack[],int n){
	if(top == -1)
		return true;
	else
		return false;
}

Student* Top(Student*  Stack[]){
	return Stack[top];
}

//------------------------------RECURSIVE treeWalk ------------------------------

// void treeWalk(Student* root,int n){
//     if(root == NULL || n==1)
//         return;
//     treeWalk(root->left,n-1);
//     cout<<root->name<<endl;
//     treeWalk(root->right,n-1);
// }

//----------------------------NON-RECURSIVE treeWalk ----------------------------
void treeWalk(Student* root,int n){ 
	Student*  Stack[n]; 
	Student* curr = root; 
	while((curr != NULL || empty(Stack,n) == false) && (n > 0)){ 
		while (curr != NULL){ 
			push(Stack,n,curr); 
			curr = curr->left; 
		} 
		curr = Top(Stack); 
		pop(Stack,n); 

		cout << curr->name <<endl; 

		curr = curr->right; 
		n--;
	}
}

//------------------------------RECURSIVE treeWalkDESC ------------------------------

// void treeWalkDESC(Student* root,int n){
//     if(root == NULL || n==1)
//         return;
//     treeWalkDESC(root->right,n-1);
//     cout<<root->name<<endl;
//     treeWalkDESC(root->left,n-1);
// }

//----------------------------NON-RECURSIVE treeWalkDESC ----------------------------

void treeWalkDESC(Student* root,int n){ 
	Student*  Stack[n];
	Student* curr = root; 
	while((curr != NULL || empty(Stack,n) == false) && (n >= 0)){ 
		while (curr != NULL){ 
			push(Stack,n,curr); 
			curr = curr->right; 
		} 
		curr = Top(Stack); 
		pop(Stack,n); 

		cout << curr->name <<endl; 

		curr = curr->left; 
		n--;
	}
}

//------------------------------RECURSIVE treeWalkN ------------------------------

// string* treeWalkN(Student* root,string* str){
//     if(root == NULL)
//         return str;
//     str = treeWalkN(root->left,str);
//     str[i++] = root->name;
//     str = treeWalkN(root->right,str);
// 	return str;
// }

//----------------------------NON-RECURSIVE treeWalkDESC ----------------------------

string* treeWalkN(Student* root,string* str,int n){ 
	Student*  Stack[n]; 	 
	Student* curr = root; 
	while(curr != NULL || empty(Stack,n) == false){ 
		while (curr != NULL){ 
			push(Stack,n,curr); 
			curr = curr->left; 
		} 
		curr = Top(Stack); 
		pop(Stack,n); 

		str[i++] = curr->name; 

		curr = curr->right; 
	}

	return str;
}