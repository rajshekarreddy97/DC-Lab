#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  int nthreads, tid, procs, maxt, inpar, dynamic, nested;

  #pragma omp parallel private(nthreads, tid)
  {
    tid = omp_get_thread_num();

    if(tid == 0)
    {
      printf("Thread %d getting environment info", tid);

      procs = omp_get_num_procs();
      nthreads = omp_get_num_threads();
      maxt = omp_get_max_threads();
      inpar = omp_in_parallel();
      dynamic = omp_get_dynamic();
      nested = omp_get_nested();


      printf("Number of processors = %d\n",procs);
      printf("Number of threads = %d", nthreads);
      printf("Max threads = %d", maxt);
      printf("In parallel = %d",inpar);
      printf("Dynamic Threads enabled = %d",dynamic);
      printf("Nested parallelism supported = %d",nested);
    }
  }
}
