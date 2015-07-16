#include <factors.h>
#include <debug.h>
#include <numbers.h>

int main(int argc, char **argv){
	if (argc == 2){
		std::string aString = argv[1];
		if (isInt(aString)){
			int a = toInt(aString);
			std::vector<int> vector_factors;
				get_factors(vector_factors, a);
			std::cout << "Factors of " << a << ":" << std::endl;
			print_vector(vector_factors);
		}
	}
	else{
		std::cout << "It need one integer number to work" << std::endl;
	}
	return 0;
}
