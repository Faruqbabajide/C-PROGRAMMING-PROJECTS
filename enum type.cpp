#include <iostream>
using namespace std;
typedef enum week{
	sunday ,monday, tuesday , wednesday , thursday , friday , saturday }
	
;
int main ()
{
	week today ;
	today = monday ;
	if(today == 1){
		cout<< "Today Is monday";
	}else{
			cout<< "Today Is not monday";
	}
	

	return 0;
}