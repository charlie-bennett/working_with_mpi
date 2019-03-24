#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define buffer_size 64


//Problem 2.1

int read_file(int* buffer)
{

	FILE* my_file = fopen ("number.txt", "r");
	if (my_file == NULL) {return 1;}
	int index = 0;
	fscanf(my_file, "%d", (buffer + index));
	while ((!(feof(my_file))) && index < (buffer_size - 1))
	{
		index++;
		fscanf(my_file, "%d", (buffer + index));
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
	int output[size];
	int buffer_in[buffer_size / size];



	int buffer[buffer_size];
	int runsum;
	int start_index = (rank) * (buffer_size / size);
	int end_index = start_index + (buffer_size / size);




	if (rank == 0)
	{

		read_file(buffer);
	}

	MPI_Scatter(buffer, (buffer_size / size), MPI_INT, buffer_in, MPI_INT, 0, MPI_COMM_WORLD);




	for (i = start_index; i < end_index; i++)
	{
		runsum = runsum + buffer[i];
	}



	MPI_Gather(&runsum, 1, MPI_INT, output, 1, MPI_INT, 0, MPI_COMM_WORLD);

	runsum_buff = 0;


	for (i = 0; i < size; i++)
	{
		runsum_buff = runsum_buff + output[i];
	}

	if (rank == 0)
	{
		printf("The sum is ", runsum_buff);
	}







	MPI_Finalize();
	return 0;
}