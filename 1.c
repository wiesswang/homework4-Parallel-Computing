#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i,j;
	int k=0;
	int rank,size;
	double start,end;
	
	FILE *fp;
	fp = fopen ("result.txt","w");
	if (fp ==NULL)
	{
		printf ("faile open the file!\n");
		exit (-1);
	}
	
	//clock_t start,end;
	
	MPI_Init(0,0);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	MPI_Barrier(MPI_COMM_WORLD);
	start = MPI_Wtime();	
	for (i = 2; i < 100000; i++)
       	{
		for (j = 2; j <= sqrt(i); j++)
              	{
                      	if (i % j == 0)
                       	{
                               	break;
                       	}
               	}
               	if(j > sqrt(i))
               	{
                       	fprintf (fp,"%d ",i);
			k++;
                }
	}	
	end = MPI_Wtime();
	MPI_Barrier(MPI_COMM_WORLD);
	
	if(rank==0){
    printf("时间：Elapsed time is %.16g seconds\n",end-start );
    printf("时间精度是 %.16g seconds\n",MPI_Wtick());
    printf("素数的个数为:%d 个\n",k);
	}
	MPI_Finalize();
	return 0;
}
