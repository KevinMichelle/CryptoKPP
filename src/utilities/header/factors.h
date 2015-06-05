#ifndef __factors_H_INCLUDED__
#define __factors_H_INCLUDED__

#include <vector>

void find_factors(std::vector<int> &factors, int number);

void find_factors(std::vector<int> &factors, int number){ // find the factors of a number
	if (number > 1){
		for (int possible_divisor = 2; possible_divisor <= number ; possible_divisor++){
			while (number % possible_divisor == 0){
				number = number / possible_divisor;
				factors.push_back(possible_divisor);
			}
			if (number == 1){
				break;
			}
		}
	}
	else if (number == 1){
		factors.push_back(1);
	}
}

#endif
