#include <iostream>
using namespace std;
union unionjob {
	char name[32];
	float salary;
	int workerno;
	
}Ujob;
  struct Structjob{
	char name[32];
	float salary;
	int workerno;
	
	}s;

int main (){
 cout<<"size of union in byte"<<sizeof(Ujob)<<endl;
 cout<<"size of structure in byte"<<sizeof(s)<<endl;

return 0;	
}