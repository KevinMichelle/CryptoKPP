#include <divisors.h>
#include <factors.h> //implicitly included in divisors.h
#include <numbers.h>
#include <debug.h>

int main(int argc, char **argv){
	if (argc == 2){
		std::string aString = argv[1];
		if (isInt(aString)){
			int a = toInt(aString);
			std::vector<int> vector_divisors;
			get_divisors(vector_divisors, a);
			std::cout << "Divisors of " << a << ":\n\t";
			print_vector(vector_divisors);
			std::vector<int> vector_factors;
			std::cout << "Factors of " << a << ":\n\t";
			get_factors(vector_factors, a);
			print_vector(vector_factors);
		}
	}
	else{
		std::cout << "It need one integer number to work" << std::endl;
	}
	return 0;
}
