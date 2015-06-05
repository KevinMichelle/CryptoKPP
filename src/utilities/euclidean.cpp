#include <euclidean.h>
#include <iostream>
#include <tuple>
#include <numbers.h>

int main(int argc, char **argv){
	if (argc == 3){
		std::string aString = argv[1];
		std::string bString = argv[2];
		if (isInt(aString) and isInt(bString)){
			int a, b;
			a = toInt(aString);
			b = toInt(bString);
			int answer = gcd(a, b);
			std::cout << "gcd of " << a << " and " << b << " = " << answer << std::endl;
		}
	}
	else{
		std::cout << "It need two integers numbers to work" << std::endl;
	}
	return 0;
}
