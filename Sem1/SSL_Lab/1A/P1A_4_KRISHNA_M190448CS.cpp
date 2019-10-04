#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct Course{
	string code;
	string name;
	int credits;
};

void CreateList(struct Course arr[],int n){
	cout<<"Enter the course deatils here."<<endl;
	for(int i=0;i<n;i++){
		cout<<"Enter Course Code: ";
		cin>>arr[i].code;
		
		cout<<"Enter Course name(short name of 3 characters): ";
		cin>>arr[i].name;

		cout<<"Enter the Course credits: ";
		cin>>arr[i].credits;
		cout<<"\n";
	}
} 

int getCredit(struct Course arr[],int n,string key){
	for(int i=0;i<n;i++){
		if(!(key.compare(arr[i].code)))
			return arr[i].credits;
	}
	return 0;
}

void createFile(struct Course arr[],int n){
	ofstream file;
	file.open("file1.txt",ios::out);
	file<<"Course Code		Course Name		Credits\n";
	for(int i=0;i<n;i++){
		file<<arr[i].code<<"		"<<arr[i].name<<"		"<<arr[i].credits<<"\n";
	}
	file.close();

}

int main(){
	int n,value;
	string key;
	cout<<"Enter the number of Courses: ";
	cin>>n;
	struct Course arr[n];
	CreateList(arr,n);
	cout<<"Enter the Course code of the Course whose credits need to be displayed: ";
	cin>>key;
	value = getCredit(arr,n,key);
	cout<<"credits are "<<value<<endl;
	createFile(arr,n);

	return 0;	
}
