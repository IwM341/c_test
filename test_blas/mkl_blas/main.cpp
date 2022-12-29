#include <iostream>
#include <vector>
#include <cblas.h>
#include <chrono>
using namespace std;

#define vtype float
#define vgemm cblas_sgemm

int main()
{
    cout << "Hello World!" << endl;

    size_t fac = 2;
    const int m = 1024*fac;
    const int n = 1024*fac;
    const int k = 1024*fac;

    const vtype alpha = 0.7f;
    const vtype beta = 0.0f;

    const int a_ld = k;
    const int b_ld = n;
    const int c_ld = n;

    auto host_a = std::vector<vtype>(m*k);
    auto host_b = std::vector<vtype>(k*n);
    auto host_c = std::vector<vtype>(m*n);

    vtype sumA = 0;
    for(size_t i=0;i<m;++i){
        for(size_t j=0;j<k;++j){
            host_a[i*k+j] = 1.0/(i+j+1);
            sumA += host_a[i*k+j]*host_a[i*k+j];
        }
    }
    std::cout <<"matrix A sum2 = " <<sumA <<std::endl;
    std::cout <<"matrix B" <<std::endl;
    for(size_t i=0;i<k;++i){
        for(size_t j=0;j<n;++j){
            host_b[i*n+j] = 1.0/(i+j+1);
        }
    }


    const char TransB = 0;
    const char TransA = 0;


    std::vector<decltype(host_a)> A(1);
    std::vector<decltype(host_a)> B(A.size());
    std::vector<decltype(host_a)> C(A.size());
    for(size_t i=0;i<A.size();++i){
        A[i] = host_a;
        B[i] = host_b;
        C[i] = host_c;
    }

    std::cout << "start evaluationg" <<std::endl;
    auto start_time = std::chrono::steady_clock::now();

    for(size_t s=0;s<A.size();++s){

        vgemm(CblasRowMajor,CblasConjNoTrans,CblasConjNoTrans,m,n,k,
              alpha,A[s].data(),a_ld,B[s].data(),b_ld,beta,C[s].data(),c_ld);
            /*
        for(size_t i=0;i<n;++i){
            for(size_t j=0;j<n;++j){
                for(size_t k=0;k<n;++k){
                    C[s][i*n+j] += A[s][i*n+k]*B[s][j*n+k];
                }
            }
        }*/
    }
    auto elapsed_time = std::chrono::steady_clock::now() - start_time;
    auto time_ms = std::chrono::duration<double,std::milli>(elapsed_time).count();
    std::cout << "time: " << time_ms << "ms" <<std::endl;

    vtype sumC = 0;
      for(size_t i=0;i<m;++i){
          sumC += host_c[i*n+i];
      }
      std::cout <<"matrix Out sum = " <<sumC<<std::endl;
    return 0;
}
