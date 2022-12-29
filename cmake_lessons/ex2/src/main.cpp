#include <iostream>
#include "version.h"
int main(void){
    std::cout << "Hello world, version " << ex::getVersion()<<std::endl;
}