#ifndef __files_H_INCLUDED__
#define __files_H_INCLUDED__

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

bool file_exists(std::string filename);
void read_file(std::vector<std::string> &file_content, std::string filename);
void read_file_b(std::vector<unsigned char> &file_content, std::string filename);

bool file_exists(std::string filename){
	std::ifstream _file_ (filename);
	bool exists = false;
	if (_file_.good()){
		exists = true;
	}
	_file_.close();
	return exists;
}

void read_file(std::vector<std::string> &file_content, std::string filename){
	std::ifstream _file_ (filename);
	std::string dummy_line;
	if (_file_.is_open()){
		while ((getline (_file_, dummy_line))){
			file_content.push_back(dummy_line);
		}
	}
	else{
		std::cout << "Unable to open the file" << std::endl;
	}
	_file_.close();
}

//http://www.cplusplus.com/doc/tutorial/files/
void read_file_b(std::vector<unsigned char> &file_content, std::string filename){
	std::ifstream _file_ (filename, std::ios::in|std::ios::binary|std::ios::ate);
		/*the ifstream object now indicates that the file is available to read operations*/
	if (_file_.is_open()){
		std::streampos file_size;
		file_size = _file_.tellg();
		file_content.reserve(file_size);
		_file_.seekg(0, std::ios::beg);
		unsigned char dummy_byte;
		while (!_file_.eof()){
			_file_ >> dummy_byte;
			if (_file_.fail()){
				break;
			}
			file_content.push_back(dummy_byte);
		}
		_file_.close();
	}
	else{
		std::cout << "Unable to open the file" << std::endl;
	}
}


#endif