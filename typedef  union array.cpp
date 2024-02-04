#include <iostream>
using namespace std;
typedef union array {
	short num[10];
	char a[10];
};
int main(){
	
	union array letter; 
	for (int i=0; i< 10 ;i++){
		letter.num[i]= i + 65 ;
		
	}
	for ( int j =0; j < 10; j ++){
		cout << "number :"<< letter.num[j]<< "letter :"<<letter.a[j]<<endl;
		
	}
	return 0;
}