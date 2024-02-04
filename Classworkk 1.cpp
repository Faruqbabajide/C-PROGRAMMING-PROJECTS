#include <iostream>
using namespace std;
float a;
float b;
float c;
int main () {
	cout << "Enter the three numbers : " << endl;
	cin >> a; 
	cin >> b;
	cin >> c;
	
	if (a >b &&  a > c){
		cout << "The largest number is : " << a << endl;
	}
	
	else  if (b > a && b > c){
		cout << " The largest number is  " << b << endl; 
	}
	else if (c > a &&  c > b){
		cout << "The largest number is "<< c << endl;
	}
	else if ( a == b && a > c) {
		cout << "The largest number is " << a << endl;
	}
	else if ( a == c && a > b) {
		cout << "The largest number is " << a << endl;
	}
	else if ( b == c && b > a) {
		cout << "The largest number is " << b << endl;
	}
	else{
		cout <<"They are all equivalent"<<endl;
	}
	
	
	return 0;
}
