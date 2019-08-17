#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include "list.h"
#include "Queue.h"
using namespace std;

int num[10];

int getCredit(struct Course *arr[],string key,int n){
	for(int i=0;i<n;i++){
		if(!(key.compare(arr[i]->code)))
			return arr[i]->credits;
	}
	return 0;
}


int addStudent(struct Course *arr[],int n,string ccode){
    int index;
	char choice2 = 'a';
	string sname,name;
    for(int i=0;i<n;i++){
		if(!(ccode.compare(arr[i]->code))){
			index = i;
            break;
        }
	}
	cout<<"Enter the maxLimit of Students: ";
	cin>>arr[index]->maxLimit;
	num[index] = arr[index]->maxLimit;
	// arr[index] = new Course();
	while(choice2 == 'a' || choice2 == 'd' || choice2 == 't'){
			
			if(choice2 == 'a'){
				cout<<"Enter Student's name: ";
        		cin>>sname;
				if(arr[index]->maxLimit > 0){
    				arr[index]->regList = Insert(arr[index]->regList,sname);
					arr[index]->maxLimit = arr[index]->maxLimit - 1;
				}
				else{
					arr[index]->waitList = enQueue(arr[index]->waitList,sname);
				}
			}
			else if(choice2 == 'd'){
				cout<<"Enter Student's name: ";
        		cin>>sname;
				if(isEmptyQueue(arr[index]->waitList)){
					arr[index]->regList = Delete(arr[index]->regList,sname);
					arr[index]->maxLimit = arr[index]->maxLimit + 1;
				}
				else{
					arr[index]->regList = Delete(arr[index]->regList,sname);
					name = returnName(arr[index]->waitList);
					arr[index]->waitList = deQueue(arr[index]->waitList);
					arr[index]->regList = Insert(arr[index]->regList,name);
				}
			}
			else if(choice2 == 't'){
				treeWalk(arr[index]->regList,num[index]);
			}
			cout<<"Press 'a' to add Student ,'d' to delete and 't' to traverse: ";
        	cin>>choice2;
	}

	// print(arr[index]->regList);
	return 0;
}

void printRegListASC(struct Course *arr[],int n,string ccode){
	int index;
	for(int i=0;i<n;i++){
		if(!(ccode.compare(arr[i]->code))){
			index = i;
            break;
        }
	}
	treeWalk(arr[index]->regList,num[index]);
}

void printRegListDESC(struct Course *arr[],int n,string ccode){
	int index;
	for(int i=0;i<n;i++){
		if(!(ccode.compare(arr[i]->code))){
			index = i;
            break;
        }
	}
	treeWalkDESC(arr[index]->regList,num[index]);
}

void printRegListN(struct Course *arr[],int n,string ccode,int m,int w){
	int index;
	for(int i=0;i<n;i++){
		if(!(ccode.compare(arr[i]->code))){
			index = i;
            break;
        }
	}
	string* str = new string[num[index]];
	if(w==0)
		treeWalk(arr[index]->regList,m);
	else if(w==1){
		str = treeWalkN(arr[index]->regList,str,num[index]);
		// cout<<str[2]<<"\n"<<str[3]<<endl;
		int len = 0;
		for (int k = 0; k < num[index]; k++)
        if (str[k] != "")
            len++;
		for(int j=(len - m);j<len;j++)
			cout<<str[j]<<endl;
	}
}

int main(){
	int i=0,j=1,value,count=0;
	string key,word,line1;
	char filename[10];

	struct Course *arr[10];


	cout<<"Enter the filename: ";
	cin>>filename;

    ifstream fin(filename);

	if(!fin){
		cout<<"File doesn't exist\n";
		return 0;
	}
	
    while(fin.eof()==0){
		getline(fin,line1);
        count++;
    }


    fin.close();

    ifstream in(filename);


	if(in.eof()==0){
		getline(in,line1);
    }

    while(in>>word){
		if(j%3==1){
			arr[i] = new Course;
			arr[i]->code = word;
			j++;
		}
		else if(j%3==2){
			arr[i]->name = word;
			j++;
		}else{
			stringstream mystream(word);
			int credit = 0;
			mystream >> credit;
			arr[i]->credits = credit;
			j++;
			i++;
			
		}
			
	} 
    int choice1=6,m,w;
    string sname,ccode;

	

    while(choice1 != 5){

		cout<<" 1.Enter Student to Course\n 2.Print Ascending Order\n 3.Print Descending Order\n 4.Print N Students\n 5.Exit\n";
        cout<<"Enter your choice: ";
		cin>>choice1;
		switch(choice1){
            
            case 1: cout<<"Enter the Course Code: ";
                    cin>>ccode;
        			addStudent(arr,count-1,ccode);
                    break;

            case 2: cout<<"Enter the Course Code: ";
                    cin>>ccode;
                    printRegListASC(arr,count-1,ccode);
                    break;

			case 3: cout<<"Enter the Course Code: ";
                    cin>>ccode;
                    printRegListDESC(arr,count-1,ccode);       
                    break;

            case 4: cout<<"Enter the Course Code: ";
                    cin>>ccode;
					cout<<"Enter the Number of Students: ";
                    cin>>m;
					cout<<"Enter the value of 'w'(w=0 for top and w=1 for bottom): ";
                    cin>>w;
                    printRegListN(arr,count-1,ccode,m,w);       
                    break;


            case 5: choice1 = 5;
                    break;

			default : choice1 = 5;
                      break;
        }     

    }



    // cout<<"Enter the Course code of the Course whose credits need to be displayed: ";
	// cin>>key;
	// value = getCredit(arr,key,count-1);
	
	// cout<<"credits are "<<value<<endl;

    return 0;
}