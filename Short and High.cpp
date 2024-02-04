#include <iostream>
using namespace std;
union mix_t {
	int a ;
	struct{
		short hi ;
		short lo;
		
	}s;
	char c[4];
	
}mix;

int main (){
	cout<< "Enter the value of int a";
	cin>>mix.a;
	cout<<"the value of a is "<<mix.a<<endl;
	cout<< "Enter the value of short hi";
	cin>>mix.s.hi;
	cout<<"the value of short hi\n "<<mix.s.hi<<endl;
	cout<< "Enter the value of short lo";
	cin>>mix.s.lo;
	cout<<"the value of a is "<<mix.s.lo<<endl;
	
return 0;	
}