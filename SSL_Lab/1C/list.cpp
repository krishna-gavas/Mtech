#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include "list.h"
#include "Queue.h"

using namespace std;

int i = 0;

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

void treeWalk(Student* root,int n){
    if(root == NULL || n==1)
        return;
    treeWalk(root->left,n-1);
    cout<<root->name<<endl;
    treeWalk(root->right,n-1);
}

void treeWalkDESC(Student* root,int n){
    if(root == NULL || n==1)
        return;
    treeWalkDESC(root->right,n-1);
    cout<<root->name<<endl;
    treeWalkDESC(root->left,n-1);
}

string* treeWalkN(Student* root,string* str){
    if(root == NULL)
        return str;
    str = treeWalkN(root->left,str);
    str[i++] = root->name;
    str = treeWalkN(root->right,str);
	return str;
}