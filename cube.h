#ifndef cube_h
#define cube_h
#include <iostream>
#include <string>

enum Face {front, back, left, right, up, down};

template <class T, unsigned N> 
class Cube{
	public:
		//constructors
		Cube() {}

		Cube(T front_fill, T back_fill, T left_fill, T right_fill, T up_fill, T down_fill) {
			for (unsigned col = 0; col < N; col++){
				for (unsigned row = 0; row < N; row++){
					front_face[col][row] = front_fill;
					back_face[col][row] = back_fill;
					left_face[col][row] = left_fill;
					right_face[col][row] = right_fill;
					up_face[col][row] = up_fill;
					down_face[col][row] = down_fill;
				}
			}
		}

		//operations
		void twist(){
			twist_face(front, 1u, true);
		}

		void print_face(Face f){
			T **face = get_face(f);
			for (unsigned row = 0; row < N; row++){
				for (unsigned col = 0; col < N; col++){
					std::cout << face[col][row];
				}
				std::cout << std::endl;
			}
		}

		//accessors
		T get_square(const Face f, const unsigned row, const unsigned col) const{
		}	

	private:

		T** get_face(const Face f) {
			switch(f){
				case(front):
					return front_face;
				break;
				case(back):
					return back_face;
				break;
				case(left):
					return left_face;
				break;
				case(right):
					return right_face;
				break;
				case(up):
					return up_face;
				break;
				case(down):
					return down_face;
				break;		
			}
		}	

		void twist_face(Face f, unsigned Nr, bool clockwise) {
			//transpose face
			T **face = get_face(f);
			int new_col, new_row;
			T temp_square;
			for (unsigned row = 0; row < (N/2); row++) {
				for (unsigned col = (N+1)/2; col < N; col++) {
					new_col = row;
					new_row = col;

					temp_square = face[new_col][new_row];
					face[new_col][new_row] = face[col][row];
					face[col][row] = temp_square;
				}
			}

			T *temp;
			//reverse columns
			for (unsigned col; col < N/2; col++){
				unsigned other_col = N-1;
				temp = face[other_col];
				face[other_col] = face[col];
				face[col] = temp;
			}

		}
		
		T front_face[N][N];
		T back_face[N][N];
		T left_face[N][N];
		T right_face[N][N];
		T up_face[N][N];
		T down_face[N][N];
};

#endif
