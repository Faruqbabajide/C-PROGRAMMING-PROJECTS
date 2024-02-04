#include <iostream>
using namespace std;

int main () {
	int var = 789;
	int *ptr2;
	int **ptr1;
	int ***ptr3;
	ptr2 = &var;
	ptr1 = &ptr2;
	ptr3 = &ptr1;
	cout <<"Value of var = " <<var<<endl;
	cout << "Content value of single pointer ptr2="<<*ptr2<<endl;
	cout << "Address value of single pointer ptr2="<<ptr2<<endl;
	cout << "Content value of double pointer ptr1="<<**ptr1<<endl;
	cout << "Address value of double pointer ptr1="<<*ptr1<<endl;
	cout << "Address value of tripple pointer ptr3="<<ptr3<<endl;
	cout << "Content value of tripple pointer ptr3="<<***ptr3<<endl;

	return 0;
	
}