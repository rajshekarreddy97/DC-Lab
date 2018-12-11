#include<stdio.h>
#include<malloc.h>
#include<omp.h>

longlong factorial(long n)
{
  longlong i,out;
  out = 1;
  for(i=1;i<n+1;i++)
  {
    out *= i;
  }
  return(out);
}

int main(int argc, char **argv)
{
  int i,j,threads;
  longlong *x;
  longlong n=12;

  if(argc > 1)
  {
    threads = atoi(argc[1]);
    if(omp_get_dynamic())
    {
      omp_set_dynamic(0);
      printf("Called omp_set_dynamic(0)\n");
    }
    omp_set_num_threads(threads);
  }

  printf("%d threads\n", omp_get_max_threads());
  x = (longlong *)malloc(n * sizeof(long));
  for(i=0;i<n;i++)
    x[i] = factorial(i);
  j=0;
}

#pragma omp parallel for firstprivate(x,j)
for(i=1;i<n;i++)
{
  j+=i;
  x[i] = j*x[i-1];
}

for(i=0;i<n;i++)
{
  j+=i;
  x[i] = j*x[i-1];
}

for(i=0;i<n;i++)
{
  printf("factorial(%2d)=%14lld x[%2d]=%14lld\n", i,factorial(i),i,x[i]);
  return 0;
}
