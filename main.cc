#include <iostream>
#include "cube.h"

int main(){
	Cube <char, unsigned(3)> c('f', 'b','l','r','u','d');
	c.set_square(front, 0,0, 'x');
	c.set_square(front, 1,1, 'x');
	c.print_face(front);
	std::cout << "---------------" << std::endl;
	c.twist(front, 1u, true);
	std::cout << "---------------" << std::endl;
	c.print_face(front);
}
