Charles Bennett
PA3
USC ID: 8311964095

README: 

TORUN: 

For all included files, 

To compile simply write 

mpicc -o run -O3 p1.c
mpicc -o run -O3 p2_1.c
mpicc -o run -O3 p2_2.c
mpicc -o run -O3 p2_3.c

To run each file, simply type

srun -n4 ./run

I have had issues getting outputs out of all of the files. 

Part 1 output

---------- Begin SLURM Prolog ----------
Job ID:        2949264
Username:      cfbennet
Accountname:   lc_xq
Name:          run
Partition:     quick
Nodelist:      hpc3771
TasksPerNode:  4
CPUsPerTask:   Default[1]
TMPDIR:        /tmp/2949264.quick
SCRATCHDIR:    /staging/scratch/2949264
Cluster:       uschpc
HSDA Account:  false
---------- 2019-03-23 22:04:46 ---------
Process 0: Initially Message = 451 
Process 3: Message = 454 
Process 2: Message = 453 
Process 1: Message = 452 

Part 2 Output





