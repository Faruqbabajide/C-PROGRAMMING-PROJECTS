#include <iostream>
using namespace std;
struct book {
	char title[50]= "C++ Programming";
	char a[50]="Bjarne Stroustrup";
union {
	int dollar ;
	int yen ;
}; 
} book;
int main(){
	cout << "book Title"<< book.title<<endl;
	cout << "book author"<< book.a<<endl;
	cout << "book price in dollar :"<< book.dollar<<"$"<<endl;
	cout << "book Price in yen :"<< book.yen<<"$"<<endl;
	return 0;
}