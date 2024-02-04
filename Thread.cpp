#include <iostream>
#include <thread>
using namespace std;
 void printx(){
 	for (int i=0 ; i<=500 ; i++){
	 sleep(0.001);
 	cout <<"X";
 	
 }
 
 	
 }
 void printy(){
 	for (int i=0 ; i<=500 ; i++){
	 
 	cout <<"Y";
}
 }
 
 int main()
 {
 	thread t1(printx);
 
 	thread t2(printy);
 		t1.join();
 	t2.join();
 	return 0;
 }