#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
int parse_config_file(const std::string &filename){
    std::regex jsr("\"(.*)\"\\s*:\\s*\"(.*)\"");
    std::smatch sm;
    std::ifstream input_file(filename);
	if(!input_file.is_open())
		return -1;
    auto S = std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());


	std::cout << S<< '\n';


	while(regex_search(S, sm, jsr))
    {
        std::cout << sm[0] <<"*" << sm[1] <<'*'<< sm[2]   << '\n';
        S = sm.suffix();
    }

	//std::cout << "*******************************"<<std::endl;
    //for(auto & str:sm){
	//	std::cout << str<<std::endl;
	//}

	return 0;
}

int main(int argc, char **argv){
	if(argc < 2){
		std::cout<<"Good by world!"<<std::endl;
		return 0;
	}
	parse_config_file(argv[1]);
	
	return 0;
}