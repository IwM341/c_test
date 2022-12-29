#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <size_t N>
struct MultiIndex;




int main()
{
    auto start_time = std::chrono::steady_clock::now();
	auto elapsed_time = std::chrono::steady_clock::now() - start_time;
	auto time_ms = std::chrono::duration<double,std::milli>(elapsed_time).count();
	
    std::vector<double> X(100000);
    for(auto & x:X)
        x = rand()/(RAND_MAX+1.0);
        
    double sum = 0;
	size_t N = X.size();
    start_time = std::chrono::steady_clock::now();
	for(size_t i=0;i<N;++i)
		sum += X[i];
	elapsed_time = std::chrono::steady_clock::now() - start_time;
	time_ms = std::chrono::duration<double,std::milli>(elapsed_time).count();
	std::cout << "indexing, time, ms: " << time_ms <<'\t' << sum<<std::endl;
	sum = 0;


	start_time = std::chrono::steady_clock::now();
	for(MultiIndex<1> i=0;i<N;++i)
		sum += X[i];
	elapsed_time = std::chrono::steady_clock::now() - start_time;
	time_ms = std::chrono::duration<double,std::milli>(elapsed_time).count();
	std::cout << "multi indexing, time, ms: " << time_ms <<'\t' << sum<<std::endl;

    return 0;
}