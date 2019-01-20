#include <iostream>
#include "cube.h"

template <class T> 
Cube<T>::Cube() : size(unsigned(3)){}

template <class T> 
Cube<T>::Cube(const unsigned int side) : size(side){}

template <class T> 
void Cube<T>::twist(){
	std::cout << size << std::endl;
}
