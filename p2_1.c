#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define buffer_size 64


//Problem 2.1

int read_file(int buffer)
{
	FILE* my_file;
	my_file = fopen("number.txt", "r");
	if (my_file == NULL) {return 1;}
	int index = 0;
	fscanf(my_file, "%d", (buffer + index));
	while ((!(feof(my_file))) && index < buffer_size)
	{
		index++;
		fscanf(my_file, "%d", (buffer + index);
	}
	fclose(my_file);
	return 0;
}

int main(int argc, char** argv)
{

	int size, rank, i;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int MSG, dest, runsum_buff, flag = 0;

	//int count = 0;

	int buffer[buffer_size];
	int runsum;
	int start_index = (rank) * (buffer_size / size);
	int end_index = start_index + (buffer_size / size);

	read_file(buffer);


	for (i = start_index; i < end_index; i++)
	{
		runsum = runsum + buffer[i];
	}


	if (rank == 0)
	{


		for (i = 1; i < 4; i++)
		{
			MPI_Recv(&runsum_buff, 1, MPI_INT, i, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			runsum += runsum_buff;
		}
	}
	else
	{
		MPI_Send(&runsum, 1, MPI_INT, 0, rank, MPI_COMM_WORLD);
	}







	MPI_Finalize();
	return 0;
}