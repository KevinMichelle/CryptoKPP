#ifndef __numbers_H_INCLUDED__
#define __numbers_H_INCLUDED__

#include <string>
#include <stdexcept>
#include <limits>
bool isInt(std::string _string);
bool isFloat(std::string _string);
bool isNumber(std::string _string);
int toInt(std::string _string);
float toFloat(std::string _string);

//http://stackoverflow.com/a/18534114/4347066
bool isInt(std::string _string){
	if (toInt(_string) == std::numeric_limits<int>::max()){
		return false;
	}
	return true;
}

bool isFloat(std::string _string){
	if (toFloat(_string) == std::numeric_limits<float>::max()){
		return false;
	}
	return true;
}

bool isNumber(std::string _string){
	bool is_int = isInt(_string);
	bool is_float = isFloat(_string);
	return (is_int and is_float);
}

int toInt(std::string _string){
	int dummy = std::numeric_limits<int>::max();
	try{
		dummy = std::stoi(_string);
	}
	catch(std::invalid_argument& e){
	}
	catch(std::out_of_range& e){
	}
	return dummy;
}

float toFloat(std::string _string){
	float dummy = std::numeric_limits<float>::max();
	try{
		dummy = std::stof(_string);
	}
	catch(std::invalid_argument& e){
	}
	catch(std::out_of_range& e){
	}
	return dummy;
}

#endif