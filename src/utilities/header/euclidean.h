#ifndef __euclidean_H_INCLUDED__
#define __euclidean_H_INCLUDED__
 
#include <tuple>
 
int gcd(int a, int b); //euclidean algorithm
std::tuple<int, int> egcd(int a, int b); //extended euclidean algorithm

/*
	I need to check if must be return a 'error' value if numbers are not positive
*/

int gcd(int a, int b){
	int aux = a;
	if (b > a){
		a = b;
		b = aux;
	}
	int remainder;
	while (a % b != 0){
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return b;
}

std::tuple<int, int> egcd(int a, int b){
	int aux = a;
	if (b > a){
		a = b;
		b = aux;
	}
	int quotient, remainder, new_x, new_y;
	std::tuple<int, int> x = std::make_tuple(1, 0);
	auto y = std::make_tuple(0, 1);
	while (a % b != 0){
		quotient = a / b;
		remainder = a % b;
		a = b;
		b = remainder;
		new_x = std::get<0>(x)- (std::get<1>(x) * quotient);
		new_y = std::get<0>(y) - (std::get<1>(y) * quotient);
		x = std::make_tuple(std::get<1>(x), new_x);
		y = std::make_tuple(std::get<1>(y), new_y);
	}
	std::tuple<int, int> results (std::get<1>(x), std::get<1>(y));
	return results;
}

#endif
