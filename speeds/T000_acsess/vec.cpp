#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <array>
#include <algorithm>
#include <random>

using namespace std;

struct A{
  size_t i,j;
  A(size_t i = 32,size_t j=64):i(i),j(j){}
};

struct B{
    size_t i,j;
    B(const A & a):i(a.i),j(a.j){}
};

enum method{
	INDEXING,
	INDEXING_FIX_N,
	ITERATOR,
	ITERATOR_FIX_END,
	AUTO_REF_CONSTRUCTION,
	POINTER,
	POINTER_FIX_END
};

template <typename T>
std::string TypeString(){
    std::string fname = __PRETTY_FUNCTION__ ;
    return fname.substr(35,fname.size()-84);
}
#define TypeToString(type) TypeString<type>()

template <typename EnumClass>
struct EnNameStr{
	template <EnumClass em>
	static std::string _str(){
		std::string enum_name = __PRETTY_FUNCTION__ ;
		return  enum_name.substr(69,enum_name.size()-135);
	}
};
#define ValueToString(V) EnNameStr<decltype(V)>::_str<V>()


const std::string method_name(method M){
	switch (M){
		case INDEXING:
			return "INDEXING";
		case INDEXING_FIX_N:
			return "INDEXING_FIX_N";
		case ITERATOR:
			return "ITERATOR";
		case ITERATOR_FIX_END:
			return "ITERATOR_FIX_END";
		case AUTO_REF_CONSTRUCTION:
			return "AUTO_REF_CONSTRUCTION";
		case POINTER:
			return "POINTER";
		default:
			return "";
	}
}

template <method M>
struct worker{
	template <typename Container>
	static auto work(Container &X);
	static std::string m_name();
};



template <>
struct worker<INDEXING>{
	template <typename Container>
	static auto work(Container &X){
		decltype(X[0]+0) summ = 0;
		for(size_t i=0;i<X.size();++i){
			X[i] = rand()/(RAND_MAX+1.0);
		}
		for(size_t i=0;i<X.size();++i){
			summ += X[i];
		}
		return summ;
	}

	static std::string m_name(){
		return ValueToString(INDEXING);
	}
};

template <>
struct worker<INDEXING_FIX_N>{
	template <typename Container>
	static auto work(Container &X){
		decltype(X[0]+0) summ = 0;
		size_t N  = X.size();
		for(size_t i=0;i<N;++i){
			X[i] = rand()/(RAND_MAX+1.0);
		}
		for(size_t i=0;i<N;++i){
			summ += X[i];
		}
		return summ;
	}
	static std::string m_name(){
		return ValueToString(INDEXING_FIX_N);
	}
};

template <>
struct worker<ITERATOR>{
	template <typename Container>
	static auto work(Container &X){
		decltype(X[0]+0) summ = 0;
		for(auto it = X.begin();it!=X.end();++it){
       		*it = rand()/(RAND_MAX+1.0);
		}
		for(auto it = X.begin();it!=X.end();++it){
			summ += *it;
		}
		return summ;
	}
	static std::string m_name(){
		return ValueToString(ITERATOR);
	}
};

template <>
struct worker<ITERATOR_FIX_END>{
	template <typename Container>
	static auto work(Container &X){
		decltype(X[0]+0) summ = 0;
		auto end = X.end();
		for(auto it = X.begin();it!=end;++it){
			*it = rand()/(RAND_MAX+1.0);
		}
		for(auto it = X.begin();it!=end;++it){
			summ += *it;
		}
		return summ;
	}
	static std::string m_name(){
		return ValueToString(ITERATOR_FIX_END);
	}
};



template <>
struct worker<AUTO_REF_CONSTRUCTION>{
	template <typename Container>
	static auto work(Container &X){
		decltype(X[0]+0) summ = 0;
		for(auto & it:X){
			it = rand()/(RAND_MAX+1.0);
		}
		for(const auto & it:X){
			summ += it;
		}
		return summ;
	}
	static std::string m_name(){
		return ValueToString(AUTO_REF_CONSTRUCTION);
	}
};


template <>
struct worker<POINTER>{
	template <typename Container>
	static auto work(Container &X){
		decltype(X[0]+0) summ = 0;
		double * p_start = X.data();
		double * p_end = X.data()+X.size();
		for(double * it = p_start;it != p_end;++it){
			*it = rand()/(RAND_MAX+1.0);
		}
		for(double * it = p_start;it != p_end;++it){
			summ += *it;
		}
		return summ;
	}
	static std::string m_name(){
		return ValueToString(POINTER);
	}
};

#define declare_switch(M) case M:\
							return worker<M>::work(X);
template <typename Container>
auto work(Container & X,method M){
	switch (M){
		declare_switch(INDEXING)
		declare_switch(INDEXING_FIX_N)
		declare_switch(ITERATOR)
		declare_switch(ITERATOR_FIX_END)
		declare_switch(AUTO_REF_CONSTRUCTION)
		declare_switch(POINTER)
		default:
			worker<INDEXING>::work(X);
	}
	return worker<INDEXING>::work(X);
}

int main()
{
    constexpr size_t N = 100000;
    //std::vector<double> X(N);
	std::array<double,N> X;
    double summ =0 ;
	


    auto start_time = std::chrono::steady_clock::now();
	auto elapsed_time = std::chrono::steady_clock::now() - start_time;
	auto time_ms = std::chrono::duration<double,std::milli>(elapsed_time).count();

	const std::vector<method> METHODS({INDEXING,
	INDEXING_FIX_N,
	ITERATOR,
	ITERATOR_FIX_END,
	AUTO_REF_CONSTRUCTION,
	POINTER});

	//for(auto &M: METHODS){
	//	std::cout << M << "\t" <<  method_name(M) <<std::endl;
	//}

	for(auto &M: METHODS){
		start_time = std::chrono::steady_clock::now();
		auto summ =  work(X,M);
		elapsed_time = std::chrono::steady_clock::now() - start_time;
		time_ms = std::chrono::duration<double,std::milli>(elapsed_time).count();
		std::cout<<method_name(M)<<std::endl;
		std::cout<<"time, ms " <<time_ms <<std::endl;
		std::cout<<"sum " <<summ <<std::endl;

	}


    return 0;
}
