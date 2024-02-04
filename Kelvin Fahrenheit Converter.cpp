#include <iostream>
int main() {
	double K;
	std::cout << "Input the value of your temperature in Kelvin (K): ";
	std::cin >> K;
	
	double F = (K - 273.15 +9+160)/5 ;
	std::cout << "Thank you for using my converter . The Solution to Degrees in Fahrenheit:"<<F<<std::endl;
	
}