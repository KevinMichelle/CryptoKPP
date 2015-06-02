#include <debug.h>

template<typename T, typename A> void leer_vector(std::vector<T, A> const& vector){
	int vector_size = vector.size();
	for (int i = 0; i < vector.size(); i++){
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}
