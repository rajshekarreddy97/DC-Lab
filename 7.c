#include<stdio.h>
#include<omp.h>
#define MAX 65535;

main()
{
  int *arr,i,n,cur_max,cur_val;
  omp_lock_t MAXLOCK;

  printf("Enter the no of elements\n");
  scanf("%d",&n);

  if(n<=0)
  {
    printf("The array elements cannot be stored");
    exit(1);
  }

  arr = (int *)malloc(sizeof(int) * n);
  srand(MAX);

  for(i=0;i<n;i++)
  {
    arr[i] = rand();
  }

  if(n==1)
  {
    printf("The largest element in the array is %d", arr[0]);
    exit(1);
  }

  printf("The lock is going to start\n");
  omp_set_num_threads(8);
  omp_init_lock(&MAXLOCK);
  cur_max = -9999;
  printf("The lock has been initialised\n");

  #pragma omp parallel for
  for(i=0;i<n;i++)
  {
    if(arr[i]>cur_max)
    {
      omp_set_lock(&MAXLOCK);
      if(arr[i]>cur_max)
      {
        cur_max = arr[i];
        omp_unset_lock(&MAXLOCK);
      }
    }
  }

  free(arr);
  printf("The largest Number of the array is %d",cur_max);

}
