#include<stdio.h>
#include<omp.h>

int main()
{
  #pragma omp parallel

  printf("Hello World! This is thread %d of %d", omp_get_thread_num(), omp_get_num_thread());

}
