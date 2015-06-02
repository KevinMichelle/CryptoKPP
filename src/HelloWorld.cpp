#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void imprimirNumeros(int *arreglo, int LIMTE);
void imprimirVector(std::vector<int> &vectorEnteros);
void abrirArchivo(char *nombre);
bool existeArchivo(char *nombre);
void abrirArchivoBinario(char *nombre);
void leerVector(std::vector<unsigned char> &vector); // i need learn to use templates

void imprimirNumeros(int *arreglo, int LIMITE){
	if (arreglo == NULL){
		std::cout << "Arreglo no inicializado, NO HACER NADA" << std::endl;
	}
	else{
		for (int i = 0; i < LIMITE; i++){
			arreglo[i] = i * 10;
			std::cout << "Arreglo(" << i << ") en " << &arreglo[i] << " es igual a: " << arreglo[i] << std::endl;
		}
	}
}



void imprimirVector(std::vector<int> &vectorEnteros){
	std::cout << "Hola" << std::endl;
	int limite = 5;
	for (int i = 0; i < limite; i++){
		vectorEnteros.push_back(i);
	}
	int vectorSize = vectorEnteros.size();
	std::cout << "Size vector: " << vectorSize << std::endl;
	std::cout << "LIMITE del Vector: " << vectorEnteros.max_size() << std::endl;
	for (int i = 0; i < vectorEnteros.size(); i++){ // i like iterators, but because i am learning i prefer use this first
		std::cout << vectorEnteros[i] << std::endl;
	}
}

void leerVector(std::vector<unsigned char>  &vector){
	int vectorSize = vector.size();
	for (int i = 0; i < vector.size(); i++){
		std::cout << vector[i] << " - " << (int)vector[i] << std::endl;
	}
}

void abrirArchivo(char *nombre){
	std::ifstream archivo (nombre);
	std::string line;
	std::cout << "Existe archivo: " << nombre << ": " << existeArchivo(nombre) << std::endl;
	if (archivo.is_open()){
		std::cout << "Abrir: " << nombre << std::endl;
		while ((getline (archivo, line))){
			std::cout << "\t" << line << std::endl;
		}
	archivo.close();
	}
	else{
		std::cout << "Incapaz de abrir" << std::endl;
	}
}


//http://www.cplusplus.com/doc/tutorial/files/
void abrirArchivoBinario(char *nombre){
	std::ifstream archivo (nombre, std::ios::in|std::ios::binary|std::ios::ate);
	//objeto ifstream que indica que el archivo se abre para operaciones de lectura
	//se le da permiso de escritura, se lee en modo binario y se posiciona el streaming al final del archivo
	if (archivo.is_open()){
		std::cout << "Leer el archivo en modo binario" << std::endl;
		std::streampos size_file; //objeto que toma como referencia la posicion del streamin
		//notar que si se posiciona el streaming al final del archivo entonces se puede saber su tam
		size_file = archivo.tellg(); //indica la posicion actual del stream
		std::vector<unsigned char> bytesArchivo;
		bytesArchivo.reserve(size_file);
		archivo.seekg(0, std::ios::beg);
		unsigned char byte;
		while (!archivo.eof()){ //mientras no se llegue al final del archivo
			archivo >> byte; //stream en tal posicion guarda su valor en la variable caracter sin signo
			//std::cout << byte << std::endl;
			if (archivo.fail()){
				break;
			}
			bytesArchivo.push_back(byte); //poner el byte en el vector de caracteres sin signo
		}
		//now i should have a vector of unsigned chars, right? well, i want to know what is in the vector of bytes
		leerVector(bytesArchivo);
		archivo.close();
	}
	else{
		std::cout << "Incapaz de abrir" << std::endl;
	}
}

bool existeArchivo(char *nombre){
	std::ifstream archivo (nombre);
	bool existe = false;
	if (archivo.good()){
		existe = true;
	}
	archivo.close();
	return existe;
}


int main(int argc, char *argv[]){


	std::cout << "Hello World in C++!" << "- Count argc: " << argc << std::endl;
	
	std::cout << "Primer argumento: " << argv[0] << std::endl;
	
	int *arreglo = NULL; //puntero entero llamado arreglo
	std::cout << "Puntero de arreglo (debe ser 0 porque es NULO): " << arreglo << std::endl;
	std::cout << std::endl;
	arreglo = new int[10];
	std::cout << "Puntero de arreglo (ya inicializado): " << arreglo << std::endl;
	std::cout << std::endl;
	int LIMITE = 10;
	
	imprimirNumeros(arreglo, LIMITE);
	
	delete [] arreglo;
	arreglo = NULL;
	imprimirNumeros(arreglo, LIMITE); //No debe crashear porque si el puntero es NULO entonces la funcion no hace nada
	
	std::vector<int> vectorEnteros; //vector facio
	imprimirVector(vectorEnteros);
	
	bool VERDADERO = true, FALSO = false;
	std::cout << VERDADERO << " - " << FALSO << std::endl;
	
	if (argc == 2){
		//abrirArchivo(argv[1]); // es un arreglo, lo trata como tal
		abrirArchivoBinario(argv[1]);
	}
	return 0;
}
