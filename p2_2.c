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
		print
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



	int buffer[buffer_size];
	int runsum;
	int start_index = (rank) * (buffer_size / size);
	int end_index = start_index + (buffer_size / size);




	if (rank == 0)
	{

		read_file(buffer);
	}
	MPI_Bcast(buffer, buffer_size, MPI_INT, 0, MPI_COMM_WORLD);




	for (i = start_index; i < end_index; i++)
	{
		runsum = runsum + buffer[i];
	}

	MPI_Reduce(&runsum, &runsum_buff, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		printf("The sum is ", runsum_buff);
	}







	MPI_Finalize();
	return 0;
}