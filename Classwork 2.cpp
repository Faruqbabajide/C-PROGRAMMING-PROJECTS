#include <iostream>

using namespace std;
 int main () {
	char letter;
	cout << "Enter the letter :" <<endl;
	cin >> letter;
	 if (letter == 'A' || 'a' || 'E'|| 'e'|| 'i'|| 'I'|| 'o'|| 'O' || 'u'|| 'U'){
	 	cout<<"This is a Vowel" << endl;
	 
	  if (letter =='B' || 'b'|| 'c'||  'C' || 'D' || 'd' || 'F' || 'f'||'g' || 'G'||'g' || 'h'|| 'H'|| 'j' || 'J' || 'k' || 'K' || 'l'||'L' || 'M'||'m' || 'N'|| 'n'|| 'p' || 'P' || 'q' || 'Q' || 'r'||'R' || 'S'||'s' || 'T'|| 't'|| 'V' || 'v' || 'W' || 'w' || 'X'||'x' || 'Y' ||'y'||'Z'||'z'){
	 	
	 	cout<<"This is a consonant"<<endl;
	 }
	 else{
	 	cout<< "This is a special character" <<endl;
	 }
	 return 0;
	 
}
}