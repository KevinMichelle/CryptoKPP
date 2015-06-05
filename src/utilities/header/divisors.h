#ifndef __divisors_H_INCLUDED__
#define __divisors_H_INCLUDED__

#include <vector>
#include <algorithm>
#include <map>
#include <factors.h>
#include <statistics.h>

void find_divisors(std::vector<int> &divisors, std::vector<int> &factors); //it does the work
void find_divisors(std::vector<int> &divisors, int number); //interface, if the programmer only want 

void find_divisors(std::vector<int> &divisors, std::vector<int> &factors){
	std::map<int, int> frecuency_numbers;
	frecuency(frecuency_numbers, factors);
	int last_position_vector;
	int temporal_factor;
	int factor = 0;
	int frec = 0;
	int size_vector_factors = factors.size();
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
}

void find_divisors(std::vector<int> &divisors, int number){
	std::vector<int> factors;
	find_factors(factors, number);
	find_divisors(divisors, factors);
}

#endif
