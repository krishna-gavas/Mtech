#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include "list.h"
#include "Queue.h"
using namespace std;

int num[10];
int waitCount[10];

int addStudent(struct Course *arr[],int n,string ccode){
    int index = -1,p;
	int choice2 = 1;
	string sname,name;
    for(int i=0;i<n;i++){
		if(!(ccode.compare(arr[i]->code))){
			index = i;
            break;
        }
	}
	if(index == -1){
		cout<<"Enter a valid Course code"<<endl;
		return 0;
	}
	cout<<"Enter the maxLimit of Students: ";
	cin>>arr[index]->maxLimit;
	num[index] = arr[index]->maxLimit;
	waitCount[index] = num[index];
	arr[index]->A = new Waiting[num[index]];
	while(choice2 == 1 || choice2 == 2 || choice2 == 3 || choice2 == 4){
			
			if(choice2 == 1){
				cout<<"Enter Student's name: ";
        		cin>>sname;
				if(arr[index]->maxLimit > 0){
    				arr[index]->regList = Insert(arr[index]->regList,sname);
					arr[index]->maxLimit = arr[index]->maxLimit - 1;
				}
				else if(waitCount[index] > 0){
					cout<<"Enter Priority: ";
					cin>>p;
					arr[index]->A = HeapInsert(arr[index]->A,sname, p);
					waitCount[index] = waitCount[index] - 1;
					for(int i=1;i <= num[index];i++){
						if(arr[index]->A[i].priority != 0){
							cout<<arr[index]->A[i].priority<<" "<<arr[index]->A[i].name<<endl;	
						}		
					}
				}
				else
					cout<<"WaitList limit reached"<<endl;
			}
			else if(choice2 == 2){
				cout<<"Enter Student's name: ";
        		cin>>sname;
				if(isEmptyHeap(arr[index]->A)){
					arr[index]->regList = Delete(arr[index]->regList,sname);
					arr[index]->maxLimit = arr[index]->maxLimit + 1;
				}
				else{
					arr[index]->regList = Delete(arr[index]->regList,sname);
					name = ExtractMax(arr[index]->A);
					waitCount[index] = waitCount[index] + 1;
					arr[index]->regList = Insert(arr[index]->regList,name);
				}
			}
			else if(choice2 == 3){
				cout<<"Enter Student's name to be deleted from waiting list: ";
        		cin>>sname;
				int k;
				for(int i=1;i <= num[index];i++){
						if(arr[index]->A[i].priority != 0){
							if(!sname.compare(arr[index]->A[i].name)){
								k = i;
								break;
							}
						}		
				}
				arr[index]->A = deleteKey(arr[index]->A,k);

				waitCount[index] = waitCount[index] + 1;
					for(int i=1;i <= num[index];i++){
						if(arr[index]->A[i].priority != 0){
							cout<<arr[index]->A[i].priority<<" "<<arr[index]->A[i].name<<endl;	
						}		
					}
			}
			else if(choice2 == 4){
				treeWalk(arr[index]->regList,num[index]);
			}
			cout<<"1.add Student 2.delete from Normal list 3.delete from Waiting list 4.traverse: ";
        	cin>>choice2;
	}
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


    return 0;
}