#ifndef __debug_H_INCLUDED__
#define __debug_H_INCLUDED__

#include <iostream>
#include <vector>
#include <typeinfo>

//http://stackoverflow.com/a/580935/4347066
//http://stackoverflow.com/a/409396/4347066
//http://stackoverflow.com/a/19095024/4347066
template<typename T, typename A> void print_vector(std::vector<T, A> const &_vector_){
	bool is_string = (typeid(T) == typeid(std::string));
	if ((std::is_fundamental<T>::value) or is_string){
		auto dummy_iterator = _vector_.begin();
		auto dummy_element = *dummy_iterator;
		for (dummy_iterator = _vector_.begin(); dummy_iterator != _vector_.end(); ++dummy_iterator){
			dummy_element = *dummy_iterator; //get the element
			std::cout << dummy_element << std::endl; //it is very important the *
		}
	}
	else{
		std::cout << "Elements of the vector are not primitives or strings" << std::endl;
	}
}

#endif
