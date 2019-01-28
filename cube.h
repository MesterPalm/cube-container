#ifndef cube_h
#define cube_h
#include <stdlib.h>
#include <iostream>
#include <string>

enum Face {front, back, left, right, up, down};

template <class T, unsigned N> 
class Cube{
	public:
		//constructors
		Cube() {}

		Cube(T front_fill, T back_fill, T left_fill, T right_fill, T up_fill, T down_fill) {
			front_face = (T**)malloc(sizeof(T*)*N);
			back_face = (T**)malloc(sizeof(T*)*N);
			left_face = (T**)malloc(sizeof(T*)*N);
			right_face = (T**)malloc(sizeof(T*)*N);
			up_face = (T**)malloc(sizeof(T*)*N);
			down_face = (T**)malloc(sizeof(T*)*N);
		
			for (int i = 0; i< N; i++){
				front_face[i] = (T*)malloc(sizeof(T)*N);
			}for (int i = 0; i< N; i++){
				back_face[i] = (T*)malloc(sizeof(T)*N);
			}for (int i = 0; i< N; i++){
				left_face[i] = (T*)malloc(sizeof(T)*N);
			}for (int i = 0; i< N; i++){
				right_face[i] = (T*)malloc(sizeof(T)*N);
			}for (int i = 0; i< N; i++){
				up_face[i] = (T*)malloc(sizeof(T)*N);
			}for (int i = 0; i< N; i++){
				down_face[i] = (T*)malloc(sizeof(T)*N);
			}

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
		void twist(Face f, unsigned nr, bool clockwise){
			twist_face(f, nr);
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

		//getters
		T get_square(const Face f, const unsigned row, const unsigned col) const{
			T** selected_face = get_face(f);
			return selected_face[col][row];
		}	

		//setters
		void set_square(const Face f, const unsigned row, const unsigned col, T square){
			T** selected_face = get_face(f);
			selected_face[col][row] = square;
		} 

	private:
		void twist_face(Face f, unsigned nr) {
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
			
			//std::cout << "---Transposedface----" << std::endl;
			//print_face(f);
			//std::cout << "-----------------" << std::endl;

			T *temp;
			//reverse columns
			for (unsigned col=0; col < N/2; col++){
				unsigned other_col = N-1-col;
				temp = face[other_col];
				face[other_col] = face[col];
				face[col] = temp;
			}
		}

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
		
		T** front_face;
		T** back_face;
		T** left_face;
		T** right_face;
		T** up_face;
		T** down_face;
};

#endif
