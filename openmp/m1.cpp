#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>


#include <random>
#include <algorithm>
#include <iterator>

using namespace std;


int omp_thread_count() {
    int n = 0;
    #pragma omp parallel reduction(+:n)
    n += 1;
    return n;
}

int main()
{
    size_t N = 10000;
    size_t i;
    std::vector<double> X(N);
	std::vector<size_t> Indexes(N);
	for(size_t j=0;j<N;++j)
		Indexes[j] = j;
	
	std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(Indexes.begin(), Indexes.end(), g);
	

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); 
	
	#ifdef _OPENMP
	omp_set_num_threads(4);
	cout << "omp version_1, num of treads: " << omp_get_num_threads () <<std::endl;
	cout << "omp version_1, tread cout: " << omp_thread_count() <<std::endl;
	#endif
    #pragma omp parallel for shared(X) private(i)
    for(i=0;i<N;++i){
		
		#ifdef OMP_OPT
		const size_t _i = Indexes[i];
		#else
		size_t _i = i;
		#endif
		
		X[_i] =0;
		size_t sch;
        for(size_t j=0;j<_i;++j)
            sch+= 1;
		 X[_i] = sch;
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    
    std::cout << "Time difference = " << 
	std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << 
	"[mus]" << std::endl;
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
   
    /*
    for(auto const & item : X)
        cout << item << "\t";
    cout << endl;
    */

    return 0;
}