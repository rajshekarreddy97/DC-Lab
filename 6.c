#include<stdio.h>
#include<omp.h>
#define MAX 65536

main()
{
  int *arr,i,n,cur_max,cur_val;

  printf("Enter the no of elements");
  scanf("%d",&n);

  if(n<=0)
  {
    printf("Invalid");
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
      printf("The largest element is %d",arr[0]);
      exit(1);
  }

  cur_max=0;
  omp_set_num_threads(8);

  #pragma omp parallel for
  for(i=0;i<n;i++)
  {
    if(arr[i]>cur_max)
    #pragma omp critical
    if(arr[i]>cur_max)
    {
      cur_max = arr[i];
    }
  }

  free(array);
  printf("he largest Number in the array is %d\n",cur_max);
}
