#include <iostream>

int main() {
    int value;
    
    std::cout << "Enter  the value that is to be expressed in format of Hour : Minutes : ";
    std::cin >> value;
    
    int hours = value / 3600;     
    int remaining = value % 3600; 
    int minutes = remaining / 60;    
    int seconds = remaining % 60;   
    
    std::cout << "Converted time: " << hours << ":" << minutes << ":" << seconds << std::endl;
    
    return 0;
}
