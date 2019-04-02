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
	//int count = 0;
	void* MSG_buffer;
	int q, i;
	int recieve_from, send_tp;
	MSG = 0;

	for (q = 0; q < size; q++)
	{
		for (i = 0; i < size; i++)
		{
			if (rank == i)
			{
				printf("Process %d: Initially Message = %d \n", rank, MSG);
				recieve_from = i - q;
				if (q < 0)
				{
					recieve_from = recieve_from + size;
				}
				send_to = ((i + q) % size);
				if (i == 0)
				{
					printf("Process %d: Initially Message = %d \n", rank, MSG);
					MPI_Send(&MSG, 1, MPI_INT, send_to, rank, MPI_COMM_WORLD);
					MPI_Recv(&MSG, 1, MPI_INT, recieve_from, recieve_from, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					printf("Process %d: Recieved Message = %d Done! \n", rank, MSG);
				}
				else
				{
					MPI_Recv(&MSG, 1, MPI_INT, recieve_from, recieve_from, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					MSG++;
					printf("Process %d: Recieved Message = %d Done! \n", rank, MSG);
					MPI_Send(&MSG, 1, MPI_INT, send_to, rank, MPI_COMM_WORLD);
				}

			}
		}






		MPI_Finalize();
		return 0;
	}