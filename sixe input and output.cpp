#include <iostream>
#include <fstream>
using namespace std;
int main(){
	streampos begin,end;
	ifstream myfile ("example.txt");
	begin = myfile.tellg();
	myfile.seekg (A0, ios::end);
	end = myfile.tellg();
	myfile.close();
	
    cout <<"Size is :"<< (end-begin)<<"bytes";
    
	
	return 0;
	
	
}
