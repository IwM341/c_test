#include <cstdio>
#include <chrono>
#include <vector>
#include <iostream>
#define CL_USE_DEPRECATED_OPENCL_1_1_APIS // to disable deprecation warnings
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS // to disable deprecation warnings

// Includes the C++ OpenCL API. If not yet available, it can be found here:
// https://raw.githubusercontent.com/KhronosGroup/OpenCL-CLHPP/main/include/CL/opencl.hpp
#define CL_HPP_TARGET_OPENCL_VERSION 210
#define CL_TARGET_OPENCL_VERSION 210
#include "CL/opencl.h"
#include "CL/cl.hpp"

// Includes the CLBlast library
#include <clblast.h>

// =================================================================================================
#define debug(x) std::cout << #x << " = " << x <<std::endl;

#define vtype float

template <typename T>
void PrintMatrix(size_t n,size_t m,const T*data){
    for(size_t i=0;i<m;++i){
        for(size_t j=0;j<m;++j){
            std::cout << data[i*m+j] <<"\t";
        }
        std::cout << std::endl;
    }
}
// Example use of the single-precision Xgemm routine SGEMM
int main() {

  // OpenCL platform/device settings
  const auto platform_id = 0;
  const auto device_id = 0;

  // Example SGEMM arguments
  size_t fac = 2;
  const size_t m = 1024*fac;
  const size_t n = 1024*fac;
  const size_t k = 1024*fac;
  const vtype alpha = 0.7f;
  const vtype beta = 0.0f;
  const auto a_ld = k;
  const auto b_ld = n;
  const auto c_ld = n;

  // Initializes the OpenCL platform
  auto platforms = std::vector<cl::Platform>();
  cl::Platform::get(&platforms);
  if (platforms.size() == 0 || platform_id >= platforms.size()) { return 1; }
  debug(platforms.size());
  auto platform = platforms[platform_id];

  // Initializes the OpenCL device
  auto devices = std::vector<cl::Device>();
  platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);
  if (devices.size() == 0 || device_id >= devices.size()) { return 1; }
  auto device = devices[device_id];
  debug(devices.size());
  for(auto &dev : devices){
      debug(dev.getInfo<CL_DEVICE_NAME>());
  }

  // Creates the OpenCL context, queue, and an event
  auto device_as_vector = std::vector<cl::Device>{device};
  auto context = cl::Context(device_as_vector);
  auto queue = cl::CommandQueue(context, device);
  auto event = cl_event{nullptr};

  // Populate host matrices with some example data
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
  for (auto &item: host_c) { item = 0.0; }



  // Copy the matrices to the device
  auto device_a = cl::Buffer(context, CL_MEM_READ_WRITE, host_a.size()*sizeof(vtype));
  auto device_b = cl::Buffer(context, CL_MEM_READ_WRITE, host_b.size()*sizeof(vtype));
  auto device_c = cl::Buffer(context, CL_MEM_READ_WRITE, host_c.size()*sizeof(vtype));
  queue.enqueueWriteBuffer(device_a, CL_TRUE, 0, host_a.size()*sizeof(vtype), host_a.data());
  queue.enqueueWriteBuffer(device_b, CL_TRUE, 0, host_b.size()*sizeof(vtype), host_b.data());
  queue.enqueueWriteBuffer(device_c, CL_TRUE, 0, host_c.size()*sizeof(vtype), host_c.data());

  // Start the timer
  auto start_time = std::chrono::steady_clock::now();

  // Call the SGEMM routine. Note that the type of alpha and beta (float) determine the precision.
  auto queue_plain = queue();
  auto status = clblast::Gemm(clblast::Layout::kRowMajor,
                              clblast::Transpose::kNo, clblast::Transpose::kNo,
                              m, n, k,
                              alpha,
                              device_a(), 0, a_ld,
                              device_b(), 0, b_ld,
                              beta,
                              device_c(), 0, c_ld,
                              &queue_plain, &event);

  // Record the execution time
  std::cout <<"releasing event" <<std::endl;
  if (status == clblast::StatusCode::kSuccess) {
    std::cout <<"clWaitForEvents" <<std::endl;
    debug(clWaitForEvents(1, &event));
    std::cout <<"clReleaseEvent" <<std::endl;
    debug(clReleaseEvent(event));
    std::cout <<"enqueueReadBuffer" <<std::endl;
    //queue.enqueueReadBuffer(device_c,CL_TRUE,0,host_c.size()*sizeof(vtype),host_c.data());
  }
  auto elapsed_time = std::chrono::steady_clock::now() - start_time;
  auto time_ms = std::chrono::duration<double,std::milli>(elapsed_time).count();


  vtype sumC = 0;
  for(size_t i=0;i<m;++i){
      sumC += host_c[i*n+i];
  }
  std::cout <<"matrix Out sum = " <<sumC<<std::endl;


  // Example completed. See "clblast.h" for status codes (0 -> success).
  printf("Completed SGEMM in %.3lf ms with status %d\n", time_ms, static_cast<int>(status));
  return 0;
}
