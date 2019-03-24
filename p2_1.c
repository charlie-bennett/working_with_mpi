#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define buffer_size 64


//Problem 2.1

int read_file(int* buffer)
{
	/*
	MPI_File my_file;
	MPI_Status status;
	int rc = MPI_File_open(MPI_COMM_WORLD, "number.txt", MPI_MODE_RDONLY, MPI_INT, &my_file);
	printf("rc is %d \n", rc);

	rc = MPI_File_read(my_file, buffer, buffer_size, MPI_INT, &status);
	printf("rc is %d \n", rc);
	*/


	//if (my_file == NULL) {return 1;}
	FILE* my_file = fopen ("number.txt", "r");
	if (my_file == NULL) {return 1;}
	int index = 0;
	fscanf(my_file, "%d", (buffer + index));
	while ((!(feof(my_file))) && index < (buffer_size - 1))
	{
		index++;
		fscanf(my_file, "%d", (buffer + index));
	}



	MPI_File_close(&my_file);

	return 0;
}

int main(int argc, char** argv)
{

	int size, rank, i;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int MSG, dest, flag = 0;



	int buffer[buffer_size];
	int long runsum, runsum_buff;
	int start_index = (rank) * (buffer_size / size);
	int end_index = start_index + (buffer_size / size);


	read_file(buffer);



	for (i = start_index; i < end_index; i++)
	{
		runsum = runsum + buffer[i];
	}


	if (rank == 0)
	{



		for (i = 1; i < size + 1; i++)
		{
			MPI_Recv(&runsum_buff, 1, MPI_LONG, i, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			runsum += runsum_buff;
			printf("we are at this i = %d", i);
		}


		runsum += runsum_buff;
		printf("Sum is %d \n", runsum);
	}
	else
	{
		MPI_Send(&runsum, 1, MPI_LONG, 0, rank, MPI_COMM_WORLD);
	}







	MPI_Finalize();
	return 0;
}