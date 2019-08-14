#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
using namespace std;
struct Course{
	string code;
	string name;
	int credits;
};

int getCredit(struct Course *arr[],string key,int n){
	for(int i=0;i<n;i++){
		if(!(key.compare(arr[i]->code)))
			return arr[i]->credits;
	}
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


    cout<<"Enter the Course code of the Course whose credits need to be displayed: ";
	cin>>key;
	value = getCredit(arr,key,count-1);
	
	cout<<"credits are "<<value<<endl;

	return 0;
}