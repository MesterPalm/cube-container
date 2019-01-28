#include <iostream>
#include "cube.h"

void one_twist(){
	std::cout<< "--one-twist--" << std::endl;
	Cube <char, unsigned(3)> c('f', 'b','l','r','u','d');
	c.set_square(front, 0,0, 'x');
	c.set_square(front, 1,1, 'x');
	c.print_face(front);
	std::cout<< "---------" << std::endl;
	c.twist(front, 1u, true);
	c.print_face(front);
}

void two_twist(){
	std::cout<< "--two-twist--" << std::endl;
	Cube <char, unsigned(3)> c('f', 'b','l','r','u','d');
	c.set_square(front, 0,0, 'x');
	c.set_square(front, 1,1, 'x');
	c.print_face(front);
	std::cout<< "---------" << std::endl;
	c.twist(front, 1u, true);
	c.print_face(front);
	std::cout<< "---------" << std::endl;
	c.twist(front, 1u, true);
	c.print_face(front);
}
void large_two_twist(){
	std::cout<< "--large-two-twist--" << std::endl;
	Cube <char, unsigned(6)> c('f', 'b','l','r','u','d');
	c.set_square(front, 0,0, 'h');
	c.set_square(front, 0,1, 'e');
	c.set_square(front, 0,2, 'j');
	c.set_square(front, 1,1, 'x');
	c.set_square(front, 2,2, 'y');
	c.print_face(front);
	std::cout<< "---------" << std::endl;
	c.twist(front, 1u, true);
	c.print_face(front);
	std::cout<< "---------" << std::endl;
	c.twist(front, 1u, true);
	c.print_face(front);
}
int main(){
	one_twist();
	std::cout << "-----------------" << std::endl;
	two_twist();
	std::cout << "-----------------" << std::endl;
	large_two_twist();
}
