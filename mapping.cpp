#include <iostream> 
#include <iterator>
#include <map>  
using namespace std;

int main ()
{
	map<int,int>gquiz1;
	gquiz1.insert(pair<int,int>(1, 40));
	gquiz1.insert(pair<int,int>(2, 30));
	gquiz1.insert(pair<int,int>(3, 60));
	gquiz1.insert(pair<int,int>(4, 20));
	gquiz1.insert(pair<int,int>(5, 50));
	gquiz1.insert(pair<int,int>(6, 50));
	gquiz1.insert(pair<int,int>(7, 10));
	map<int , int >::iterator itr;
	cout << "\nThe map gquiz is : \n";
	cout<< "\tKey\telement\n";
	for (itr =gquiz1.begin();itr != gquiz1.end();++itr ){
		cout << '\t' << itr -> first 
	       	<<'\t'<< itr -> second <<'\n';
		
	}
	cout <<endl;
	map <int, int> gquiz2(gquiz1.begin(),gquiz1.end());
	cout<< "\ nThe map gquiz2 after"
	    << "assign from gquiq1" 

}