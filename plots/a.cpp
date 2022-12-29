#include "D:\\Important\\articles\\DMFramework\\utils\\debug\\debugdef.hpp"
#include "D:\\Important\\articles\\DMFramework\\utils\\utils"
#include <cstdio>
#include <iostream>


/*
int main(){
	auto os = tostream::save_object("0\t0\n1\t1\n2\t2\n3\t3\n");
	std::cout <<os.name() <<std::endl;
	std::ifstream F(os.name());
	
	std::string S;
	while(F>>S){
		std::cout << S <<std::endl;
	}
	std::cin>>S;
	return 0;
}
*/

int main(){
	std::string gnuplot_path = "D:\\Soft\\gnuplot\\gnuplot\\bin\\gnuplot";
	Gnuplot GP;
	
	GP.command("set yrange [-1:1]");
	GP.plot("sin(x)", "");
	GP.plot("cos(x)");
	GP.plotd(Function::GridFunction<double,Function::UniformGrid<double>,Function::LinearInterpolator>(Function::UniformGrid<double>(0,8,101),tan).toString(),
	"title \"tan\"");
	GP.show();
	
	std::cin.get();
	return 0;
}

