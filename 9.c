#include<stdio.h>
#include<omp.h>

int main(void)
{
  int i;
  omp_set_num_threads(4);

  #pragma omp parallel private(i)
  {
    int lettersperthread = 26/omp_get_num_threads();
    int thisthreadnum = omp_get_thread_num();

    int startletter = 'a' + thisthreadnum*lettersperthread;
    int endletter = 'a' + thisthreadnum*lettersperthread + lettersperthread;

    for(i=startletter;i<endletter;i++)
    {
      printf("%c",i);
    }
  }
  printf("\n");
  return 0;
}
