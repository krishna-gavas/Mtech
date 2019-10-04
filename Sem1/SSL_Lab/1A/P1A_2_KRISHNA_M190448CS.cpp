#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of Courses: ";
	cin>>n;
	string arr[n];
	for(int i=0;i<n;i++){
		cout<<"Enter Course code "<<i+1<<" : ";
		cin>>arr[i];
	}
	cout<<"The course codes are:"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
	

	return 0;	
}
