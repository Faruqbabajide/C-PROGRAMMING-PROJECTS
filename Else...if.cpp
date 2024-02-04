#include <iostream>
using namespace std;
int score = 40;
int main (){
	if (score>=70)
	  {
	 cout<<"Grade A"<<endl;
	  cout <<"Excellent"<<endl;}
	else if (score>=60)
	  {cout<<"Grade B"<<endl;
	cout <<"Good"<<endl;}
	else if (score>=50)
	  {
	  cout<<"Grade C"<<endl;
	  cout <<"Fair"<<endl;}
	else if (score>=40)
	  {
	  cout<<"Grade D"<<endl;
	  cout<<"Pass"<<endl;}
	else
	  cout <<"Grade F"<<endl;
	return 0;
	
}