#include <iostream>

#include <my_class.h>

int main(void){
	my_class<int> X(100);
	std::cout<<X<<std::endl;
	return 0;
}