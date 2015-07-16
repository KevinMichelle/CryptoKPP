#include <files.h>
#include <debug.h>
#include <vector>
#include <string>

int main(int argc, char **argv){
	if (argc > 1){
		std::string filename = argv[argc - 1];
		std::vector<std::string> text_file;
		std::vector<unsigned char> binary_file;
		if (file_exists(filename)){
			read_file(text_file, filename);
			read_file_b(binary_file, filename);
			print_vector(text_file);
			print_vector(binary_file);
		}
		else{
			std::cout << "File named '" << filename << "' not exists" << std::endl;
		}
	}
	else{
		std::cout << "Need a filename to work" << std::endl;
	}
	return 0;
}
