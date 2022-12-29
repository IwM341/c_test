#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <regex>

std::string str_toupper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), 
                // static_cast<int(*)(int)>(std::toupper)         // wrong
                // [](int c){ return std::toupper(c); }           // wrong
                // [](char c){ return std::toupper(c); }          // wrong
                   [](unsigned char c){ return std::toupper(c); } // correct
                  );
    return s;
}

bool is_macros_sym(char c){
	return ('a' <= c <= 'z') || ('A' <= c <= 'Z') || ('0' <= c <= '9') || (c == '_');
}
bool is_num(char c){
	return ('0' <= c <= '9');
}

/*
int main(int argc,char **argv){
	if(argc < 2){
		std::cout << "require filename" <<std::endl;
		return 0;
	}
	std::string fname = argv[1];
	std::string name = fname;
	if(fname.size() >=2){
		size_t i = fname.size() - 2;
		if(fname.size() >=4){
			size_t j = fname.size() - 4;
			if((fname.size() >=4) and (fname[j] == '.') and (fname[j+1]  == 'h') and (fname[j+2]  == 'p') and (fname[j+3]  == 'p')){
				name = fname.substr(0,fname.size() - 4);
			}
		}
		else if( (fname[i] == '.') and (fname[i+1]  == 'h')){
			name = fname.substr(0,fname.size() - 2);
		}
		else{

			fname += ".h";
		}
	}
	else{
		fname += ".h";
	}

	std::cout << fname <<'\n'<<name <<'\n';
	auto NAME = str_toupper(name);
	std::ofstream out(fname);
	out << "#ifndef " <<NAME + "_H" << std::endl;
	out << "#define " << NAME + "_H" << std::endl;
	out << std::endl<< std::endl;
	out << "#endif"<< std::endl;
	return 0;
}
*/

std::string code_H(const std::string& hname){
	using namespace std::string_literals;
	return "#ifndef "s+hname+"\n#define "+hname+"\n\n\n#endif//"+hname;
}

std::string code_C(){
	return "#include <stdio.h>\n\nint main(void){\n\tprintf(\"Hello world!\");\n\treturn 0;\n}";
}

std::string code_CPP(){
	return "#include <iostream>\n\nint main(void){\n\tstd::cout<<\"Hello world!\"<<std::endl;\n\treturn 0;\n}";
}

int main(int argc,char **argv){
	if(argc < 2){
		std::cout << "require filename" <<std::endl;
		return 0;
	}
	using namespace std::string_literals;
	std::string fname = argv[1];

	std::smatch m;
	
	
	

	std::string content;
	if( std::regex_match(fname,m,std::regex(R"(.*(\.c|.\C|\.cpp|\.cc)$)")) ){
		
		if(m[1] == ".c" || m[1] == ".C")
			content = code_C();
		else
			content = code_CPP();
	}
	else if( std::regex_match(fname,m,std::regex(R"(.*(\.h|.\H|\.hpp|\.hh)$)")) ){
		std::string fprs = fname;
		if( std::regex_match(fname,m,std::regex(R"(^\d.*)")) )
			fprs = "_"s + fname;

		content =  code_H(str_toupper(std::regex_replace(fprs,std::regex("\\W"), "_")));
	}
	else{
		std::cout << "incorrect filename" <<std::endl;
		return 0;
	}

	std::ofstream out(fname);
	if(!out.is_open()){
		std::cout << "can't open " << fname <<std::endl;
	}
	out << content;

	return 0;
}