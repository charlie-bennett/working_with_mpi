#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define buffer_size 8;


//Problem 2.1

int read_file(int* buffer)
{
	MPI_File my_file;
	MPI_Status status;
	int rc = MPI_File_open(MPI_COMM_WORLD, "number.txt", MPI_MODE_RDONLY, MPI_INFO_NULL, &my_file);
	rc = MPI_File_read(my_file, buffer, buffer_size, MPI_INT, &status);

	/*
	if (my_file == NULL) {return 1;}
	int index = 0;
	fscanf(my_file, "%d", (buffer + index));
	while ((!(feof(my_file))) && index < buffer_size)
	{
		index++;
		fscanf(my_file, "%d", (buffer + index));
	}
	fclose(my_file);
	return 0;
	*/
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

	int buffer[buffer_size] = {1, 2, 3, 4, 5, 6, 7, 8};
	int runsum;
	int start_index = (rank) * (buffer_size / size);
	int end_index = start_index + (buffer_size / size);


	if (read_file)
	{
		//read_file(buffer);



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
			printf("Sum is %d", runsum);
		}
		else
		{
			MPI_Send(&runsum, 1, MPI_INT, 0, rank, MPI_COMM_WORLD);
		}







		MPI_Finalize();
		return 0;
	}