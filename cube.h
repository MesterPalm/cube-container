#ifndef cube_h
#define cube_h

template <class T> 
class Cube{
	public:
		//constructors
		Cube();
		Cube(const unsigned int side);

		//operations
		void twist();

		//accessors
	private:
		const unsigned int size;

};

#endif
