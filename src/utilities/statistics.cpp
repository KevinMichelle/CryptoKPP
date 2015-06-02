#include <statistics.h>

std::map<int,int> frecuency(std::vector<int> &vector){
	int size_vector = vector.size();
	std::map<int, int> frec_map;
	int number = 0;
	for (int i = 0; i < size_vector; i++){
		number = vector[i];
		++frec_map[number];
	}
	return frec_map;
}
