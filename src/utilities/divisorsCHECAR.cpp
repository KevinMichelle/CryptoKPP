#include <divisors.h>
#include <debug.h>

struct STRUCT_factor_frec{
	int factor;
	int frec;
};

std::vector<int> divisors(std::vector<int> &vector_factors){
	STRUCT_factor_frec factor_frec; //generic struct, because i only need to use in the loops this struct always change its data
	std::vector<STRUCT_factor_frec> VECTOR_factor_frec; //vector of struct called STRUCT_factor_frec
	int size_vector_factors = vector_factors.size();
	int aux_factor = vector_factors[0];
	int aux_frec = 0;
	for (int i = 0; i < size_vector_factors; i++){
		if (vector_factors[i] == aux_factor){
			aux_frec = aux_frec + 1;
		}
		else{
			factor_frec.factor = aux_factor;
			factor_frec.frec = aux_frec;
			VECTOR_factor_frec.push_back(factor_frec);
			aux_factor = vector_factors[i];
			aux_frec = 1;
		}
		if (i == size_vector_factors - 1){
			factor_frec.factor = aux_factor;
			factor_frec.frec = aux_frec;
			VECTOR_factor_frec.push_back(factor_frec);
		}
	}
	std::vector<int> vector_divisors;
	vector_divisors.push_back(1); //1 it should be always in the vector of divisors
	int last_pos_vector;
	int aux_temp;
	if (size_vector_factors > 1){;
		for (int i = 0; i < VECTOR_factor_frec.size(); i++){
			last_pos_vector = vector_divisors.size() - 1;
			factor_frec = VECTOR_factor_frec[i]; //same struct variable, different data
			aux_factor = factor_frec.factor; //aux_factor now has a different value
			aux_frec = factor_frec.frec; //the same of before apply to aux_frec
			std::cout << "factor frec" << aux_factor << aux_frec << std::endl;
			for (int j = 0; j <= last_pos_vector; j++){
				aux_temp = aux_factor * vector_divisors[j];
				std::cout << "aux: " << aux_temp << " divisors: " <<  vector_divisors[j] << std::endl;
				for (int k = 1; k < aux_frec; k++){
					vector_divisors.push_back(aux_temp);
					aux_temp = aux_factor * aux_temp;
					std::cout << "\taux2: " << aux_temp << std::endl;
				}
			}
		}
	}
	else if (size_vector_factors == 1){
		if (vector_factors[0] != 1){
			vector_divisors.push_back(vector_factors[0]);
		}
	}
	std::sort (vector_divisors.begin(), vector_divisors.end());
	std::cout << "hola" << std::endl;
	leer_vector(vector_divisors);
	std::cout << "mundo" << std::endl;
	return vector_divisors;
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
	divisors(1);
	divisors(12);
	divisors(7);
	//find_factors(99);
	//find_factors(1);
	//find_factors(17);
	return 0;
}
