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
		if (flag == 0)
		{
			MSG = 451;
			printf("Process %d: Initially Message = %d \n", rank, MSG);
			MPI_Send(&MSG, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

		}
		else
		{
			MPI_Recv(&MSG, 1, MPI_INT, 3, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("Process %d: Recieved Message = %d Done! \n", rank, MSG);
			return 0;
		}
		count++;

	}

	else if (rank == count)
	{
		MPI_Recv(&MSG, 1, MPI_INT, (rank - 1), (rank - 1), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MSG++;
		printf("Process %d: Message = %d \n", rank, MSG);
		if (rank == 3)
		{
			count = 0;
			dest = 0;
			flag = 1;
		}
		else
		{
			dest = (rank + 1);
			count++;
		}

		MPI_Send(&MSG, 1, MPI_INT, dest, rank, MPI_COMM_WORLD);

	}




	MPI_Finalize();
	return 0;
}