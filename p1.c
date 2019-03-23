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
	void* MSG_buffer;

	if (rank == 0)
	{
		if (flag)
		{
			MSG = 451;
			printf("Process %d: Initially Message = %d", rank, MSG);
			MPI_send(&MSG, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		}
		else
		{
			MPI_Recv(&MSG, 1, MPI_INT, 3, 3, MPI_COMM_WORLD);
			printf("Process %d: Recieved Message = %d Done!", rank, MSG)
		}
	}

	else
	{
		MPI_Recv(&MSG, 1, MPI_INT, (rank - 1), (rank - 1), MPI_COMM_WORLD);
		MSG++;
		printf("Process %d: Message = %d", rank, MSG);
		MPI_send(&MSG, 1, MPI_INT, (rank + 1), rank, MPI_COMM_WORLD);
	}




	MPI_Finalize();
	return 0;
}