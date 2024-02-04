#include <iostream>
using namespace std;

 int main() {
 
     char grade = 'A';
     
     switch(grade) {
     	case 'A' : 
     	      cout<< "Excellent!"<<endl;
     	      break;
     	case 'B' : 
     	      cout<< "Well Done!"<<endl;
     	      break;
     	case 'C' : 
     	      cout<< "well done"<<endl;
     	      //break;
     	case 'D' : 
     	      cout<< "You Passed"<<endl;
     	     // break;
		case 'F' : 
     	      cout<< "Better Try"<<endl;
     	      break;
     	default : 
     	      cout<< "Invalid"<<endl;
     	      break;
			      
			      
     	      
     	
     		
	 }
     

      
	   
   return 0;
}
