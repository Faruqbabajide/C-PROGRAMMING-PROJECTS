#include <iostream>
int main() {
	double height, radius;
	std::cout << "Input the value of your Height (H): ";
	std::cin >> height;
	std::cout << "Input the value of your Radius (R): ";
	std::cin >> radius;
	
	double V = (3.142 * height * radius *radius) ;
	std::cout << "Thank you for using my calculator . The Solution to the volume of Cylinder:"<<V<<std::endl;
	
}