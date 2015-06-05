#include <divisors.h>
#include <factors.h> //already exists in divisors.h, but it is here to explicitly be aware of it
#include <numbers.h>
#include <debug.h>

int main(int argc, char **argv){
	if (argc == 2){
		std::string aString = argv[1];
		if (isInt(aString)){
			int a = toInt(aString);
			std::vector<int> vector_divisors;
			find_divisors(vector_divisors, a);
			std::cout << "Divisors of " << a << ":" << std::endl;
			leer_vector(vector_divisors);
			std::vector<int> vector_factors;
			find_factors(vector_factors, a);
			leer_vector(vector_factors);
		}
	}
	else{
		std::cout << "It need one integer number to work" << std::endl;
	}
	return 0;
}
