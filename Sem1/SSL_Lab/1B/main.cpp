#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include "list.h"
#include "Queue.h"
using namespace std;

int getCredit(struct Course *arr[],string key,int n){
	for(int i=0;i<n;i++){
		if(!(key.compare(arr[i]->code)))
			return arr[i]->credits;
	}
	return 0;
}



// int print(Student* header){
//     struct Student* temp = header;
// 	while(temp != NULL){
// 		cout<<temp->name;
// 		temp = temp->next;
// 	}
// 	return 0;
// }

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
	// arr[index] = new Course();
	while(choice2 == 'a' || choice2 == 'd'){
			cout<<"Enter Student's name: ";
        	cin>>sname;
			if(choice2 == 'a'){
				if(arr[index]->maxLimit > 0){
    				arr[index]->regList = Insert(arr[index]->regList,sname);
					arr[index]->maxLimit = arr[index]->maxLimit - 1;
				}
				else{
					arr[index]->waitList = enQueue(arr[index]->waitList,sname);
				}
			}
			else if(choice2 == 'd'){
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
			cout<<"Press 'a' to add Student and 'd' to delete: ";
        	cin>>choice2;
	}

	// print(arr[index]->regList);
	return 0;
}

int main(){
	int i=0,j=1,value,count=0;
	string key,word,line1;
	char filename[10];

	struct Course *arr[10];


	cout<<"Enter the filename: ";
	cin>>filename;

    ifstream fin(filename);
    while(fin.eof()==0){
		getline(fin,line1);
        count++;
    }


    fin.close();

    ifstream in(filename);
	if(!in){
		cout<<"File doesn't exist\n";
		return 0;
	}

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
    char choice1 = 'y';
    string sname,ccode;

	

    while(choice1 =='y' || choice1 =='Y'){
        cout<<"Enter the course code: ";
        cin>>ccode;
        addStudent(arr,count-1,ccode);
        cout<<"Do you want to add Course(y/n): ";
        cin>>choice1;     

    }



    // cout<<"Enter the Course code of the Course whose credits need to be displayed: ";
	// cin>>key;
	// value = getCredit(arr,key,count-1);
	
	// cout<<"credits are "<<value<<endl;

    return 0;
}