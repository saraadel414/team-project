#include <iostream>
#include <string>

using namespace std;
typedef string DArray;

string AddEntry(string a[], int size, string NewEntry);
string DeleteEntry(string a[],int size, string Entry_to_delete);


int main ()
{
	int size;
	cout<<"Enter the size of your array"<<endl;
	cin>> size;
	DArray* a=new DArray [size];
	for(int i=0;i<size;i++){cin>>a[i];}
	for(int i=0;i<size;i++){cout<<a[i]<<"   ";}

	while (true)
	{
		int y;
		cout<<"Enter 1 to enter A word to the array \n"<<" 2 to delete and 0 to stop the programm"<<endl;
		cin>>y;
		if(y==1){
			string New;
			cout<<"Enter the new word"<<endl;
			cin>>New;
			cout<<AddEntry (a,size,New);
		}
		else if(y==2)
		{
			string Del;
			cout<<"Enter a word to delete"<<endl;
			cin>>Del;
			cout<<DeleteEntry(a,size,Del);
		}
		else{
         cout<<"The programm stopped :("<<endl;		
		 break;
		}
	}
	

	delete [] a;
	return 0;
}
string AddEntry(string a[], int size, string NewEntry){
	string* b=new string[size+1];
	for(int i=0;i<size+1;i++){
		if(i==size){b[i]=NewEntry;}
		else{b[i]=a[i];}
	}

	for(int i=0;i<size+1;i++){

		cout <<"The new array =   " <<b[i]<<"  ";
	}
	return *b;
	delete []a;
	delete b;
}
string DeleteEntry(string a[],int size, string Entry_to_delete){
		string* b=new string[size];
		for(int i=0;i<size;i++){
			if(a[i]==Entry_to_delete){a[i]=" ";}
			
		}
		for(int j=0;j<size;j++){
			b[j]=a[j];
	}
			for(int i=0;i<size;i++){

		cout <<"The new array =   " <<b[i]<<"  ";
	}
		delete []a;
		return *b;
		delete b;
	




}
