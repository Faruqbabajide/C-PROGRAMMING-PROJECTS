#include <iostream>
using namespace std;
int main () {
	int n = 10;
loop :
	cout << n<< ",";
	n--;
	if (n>101) goto loop;
	cout << "End of Loop!\n";
	return 0;
}