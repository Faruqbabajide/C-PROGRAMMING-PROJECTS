#include <iostream>
using namespace std;

 int funct (int &a , int &b)
{
   int r;
   --a;
   --b;
   r= a+b  ;
return r;
}
int main(){
int num1 = 4 ;
int num2 =6;
cout << "Num :"<< num1<< endl ;
cout << "Num2 :"<< num2 <<endl;
int z = funct (num1, num2);
cout <<z <<endl;
cout << "Num:"<< num1<< endl ;
cout << "Num2 :"<< num2 <<endl;

}
