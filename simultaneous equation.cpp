#include <iostream>
int main() {
	double a1, b1, c1, a2, b2, c2;
	std::cout << "Enter coefficients for equation 1 (a1, b1, c1): ";
	std::cin >> a1 >> b1 >> c1;
	std::cout << "Enter coefficients for equation 2 (a2, b2, c2): ";
	std::cin >> a2 >> b2 >> c2;
	
	double determinant = a1 * b2 - a2 * b1;
	 if (determinant == 0) {
	 	 std::cout << "The system of equations has no unique solution." << std::endl;
    }  else {
        double x = (c1 * b2 - c2 * b1) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        std::cout << "Solution: x = " << x << ", y = " << y << std::endl;
    }
    return 0;
}

    
	 	