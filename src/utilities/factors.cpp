#include <factors.h>
#include <debug.h>

std::vector<int> factors(int number){ // find the factors of a number
	std::vector<int> vector_factors;
	if (number > 1){
		for (int possible_divisor = 2; possible_divisor <= number ; possible_divisor++){
			while (number % possible_divisor == 0){
				number = number / possible_divisor;
				vector_factors.push_back(possible_divisor);
			}
			if (number == 1){
				break;
			}
		}
	}
	else if (number == 1){
		vector_factors.push_back(1);
	}
	return vector_factors;
}
