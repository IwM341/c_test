#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP
#include "my_class.h"
#include <iostream>


template <typename T>
my_class<T>::my_class(){}

template <typename T>
my_class<T>::my_class(const T&x):my_class<T>::x(x){}

template <typename T>
my_class<T>::my_class(T&&x):my_class<T>::x(std::move(x)){}

template <typename T>
friend std::ostream & my_class<T>::operator<<(std::ostream &os,const my_class&mc){
    os << mc;
}

#endif//MY_CLASS_HPP