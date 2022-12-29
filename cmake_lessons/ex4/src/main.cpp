#include <iostream>
#include "version.h"

#include "src/lib.h"
int main(void){
    std::cout << "Hello world, version " << ex::getVersionS()<<std::endl;
    std::cout << "23*30=" << lib_function(20,30)<<std::endl;
}