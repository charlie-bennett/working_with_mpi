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
	int MSG, dest, flag = 0;
	int count = 0;
	void* MSG_buffer;

	if (rank == 0 && count == 0)
	{
		if (!flag)
		{
			MSG = 451;
			printf("Process %d: Initially Message = %d \n", rank, MSG);
			MPI_Send(&MSG, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
			flag = 1;
		}
		else
		{
			MPI_Recv(&MSG, 1, MPI_INT, 3, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("Process %d: Recieved Message = %d Done! \n", rank, MSG);
		}
		count++;

	}

	else if (rank == count)
	{
		MPI_Recv(&MSG, 1, MPI_INT, (rank - 1), (rank - 1), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MSG++;
		printf("Process %d: Message = %d \n", rank, MSG);
		dest = (rank == 3) ? 0 : (rank + 1);
		MPI_Send(&MSG, 1, MPI_INT, dest, rank, MPI_COMM_WORLD);
		count = (count == 3) ? 0 : count + 1;
	}




	MPI_Finalize();
	return 0;
}