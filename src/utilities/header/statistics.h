#ifndef __statistics_H_INCLUDED__#define __statistics_H_INCLUDED__
#include <map>
#include <vector>
void get_frecuency(std::map<int, int> &frec_map, std::vector<int> &vector); //maybe i need to do a template of this

void get_frecuency(std::map<int, int> &frec_map, std::vector<int> &vector){
	int size_vector = vector.size();
	int number = 0;
	for (int i = 0; i < size_vector; i++){
		number = vector[i];
		++frec_map[number];
	}
}

#endif
