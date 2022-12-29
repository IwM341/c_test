#include <iostream>
#include <fstream>

int main(void){
	std::ifstream ifs("a.txt");
	while(!ifs.eof()){
		std::string S;
		ifs >> S;
		std::cout <<S <<std::endl;
	}
	return 0;
}