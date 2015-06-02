#include <divisors.h>
#include <debug.h>

std::vector<int> divisors(std::vector<int> &factors){
	std::map<int, int> frecuency_numbers = frecuency(factors);
	int last_position_vector;
	int temporal_factor;
	int factor = 0;
	int frec = 0;
	int size_vector_factors = factors.size();
	std::vector<int> divisors;
	divisors.push_back(1);
	if (size_vector_factors > 1){
		for(std::map<int, int>::iterator iter = frecuency_numbers.begin(); iter != frecuency_numbers.end(); ++iter){
			last_position_vector = divisors.size() - 1;
			factor = iter->first;
			frec = iter->second;
			for (int i = 0; i <= last_position_vector; i++){
				temporal_factor = factor * divisors[i];
				for (int j = 0; j < frec; j++){
					divisors.push_back(temporal_factor);
					temporal_factor = factor * temporal_factor;
				}
			}
		}
	}
	else if (size_vector_factors == 1){
		if (factors[0] != 1){
			divisors.push_back(factors[0]);
		}
	}
	std::sort (divisors.begin(), divisors.end());
	return divisors;
}

std::vector<int> divisors(int number){
	std::vector<int> vector_factors = factors(number);
	leer_vector(vector_factors);
	std::vector<int> vector_divisors = divisors(vector_factors);
	return vector_divisors;
}


int main(int argc, char *argv[]){
	std::cout << "hola" << std::endl;
	if (argc == 2){
		std::string string_number = argv[1];
		std::cout << string_number << std::endl;
	}
	std::vector<int> lista_vectores = divisors(36);
	leer_vector(lista_vectores);
	//find_factors(99);
	//find_factors(1);
	//find_factors(17);
	return 0;
}
