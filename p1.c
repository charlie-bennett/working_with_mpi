#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// Problem 1

int main(int argc, char** argv)
{
	int size, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int MSG, flag = 0;

	if (rank == 0)
	{
		if (flag)
		{
			MSG = 451;
			printf("Process %d, Initially Message = %d", rank, MSG);
		}
	}

	else
	{

		MSG++;
		printf("Process %d, Message = %d", rank, MSG);
	}

	MPI_Scatter(a, 1, MPI_INT, &b, 1, MPI_INT, 2, MPI_COMM_WORLD);

	printf("Process %d: %d \n",  rank, b);

	MPI_Finalize();
	return 0;
}