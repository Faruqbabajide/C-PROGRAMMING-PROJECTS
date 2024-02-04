#include <iostream>
using namespace std;
enum week{
	sunday ,monday, tuesday , wednesday , thursday , friday , saturday }
	
;
int main ()
{
	week today ;
	today = wednesday ;
	cout << "Day "<< today+ 1;
	return 0;
}