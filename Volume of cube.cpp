#include <iostream> 
using namespace std;

int main(){
	int var = 789;
	int *ptr2;
	int **ptr1;
	ptr2 = &var;
	ptr1 =&ptr2 ;
	cout<< "var= "<<var<<endl;
	cout<< "ptr2 "<<ptr2<<endl;
	cout<< "*tr2 "<<*ptr2<<endl;
		cout<< "ptr1= "<<ptr1<<endl;
			cout<< "**r1= "<<**ptr1<<endl;
	return 0;
	
}