#ifndef MY_CLASS_H
#define MY_CLASS_H


classs std::ostream;
template <typename T>
struct my_class{
    T x;
    my_class();
    my_class(const T&);
    my_class(T&&);

    friend std::ostream & operator<<(std::ostream &os,const my_class&mc);
};

#endif//MY_CLASS_H