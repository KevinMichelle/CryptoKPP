#ifndef __debug_H_INCLUDED__
#define __debuf_H_INCLUDED__

#include <iostream>
#include <vector>

template<typename T, typename A> void leer_vector(std::vector<T, A> const& vector){ //funcion plantilla para escribir en pantalla el contenido un vector
	int vector_size = vector.size();
	for (int i = 0; i < vector.size(); i++){
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

#endif
