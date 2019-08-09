#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mpi.h" // message passing interface
using namespace std;

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah

int main (int argc, char * argv[]) {

	int my_rank;			// my CPU number for this process
	int p;					// number of CPUs that we have
	int source;				// rank of the sender
	int dest;				// rank of destination
	int tag = 0;			// message number
	char message[100];		// message itself
	MPI_Status status;		// return status for receive
	
	// Start MPI
	MPI_Init(&argc, &argv);
	
	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	// Find out the number of processes!
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	// THE REAL PROGRAM IS HERE
    srand(1231);

    // int a[10], b[10];
    // for(int x = 0; x < 10; x++)
    // {
    //     a[x] = rand() % 10;
    //     b[x] = rand() % 10;
    // }

    // int dotproduct = 0;
    // for (int x = 0; x < 10; x++)
    //     dotproduct += a[x] * b[x];

    //Know the problem

    int n = 30000;
    int * a = new int[n]; 
    int * b = new int[n];
    long int dotproduct = 0;

    if (my_rank == 0)
        for (int x = 0; x < n; x++)
        {
            a[x] = rand() % 10;
            b[x] = rand() % 10;
        }
    
    int local_n = n/p;
    int * local_a = new int[local_n];
    int * local_b = new int[local_n];

    // After executing these lines of code, local_a and local_b will have the right
    // information. Each will have the block of array a (or b) that corresponds to 
    // their local work. Each block is of size local_n
    MPI_Scatter(&a[0], local_n, MPI_INT, local_a, local_n, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(&b[0], local_n, MPI_INT, local_b, local_n, MPI_INT, 0, MPI_COMM_WORLD);     

    //Do the local work   
    long int localdot = 0;
    for (int x = 0; x < local_n; x++)
        local_dot += local_a[x] * local_b[x];
    
    //Combine results
   /*  if(my_rank != 0)
        MPI_Send(&localdot, 1, MPI_LONG, 0, tag, MPI_COMM_WORLD);
    else
    {
        dotproduct = localdot;
        long int temp;
        for (int x = 0; x < p; x++)
        {
            MPI_Recv(&temp, 1, MPI_LONG, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
            dotproduct += temp;
        }
        cout << dotproduct << endl;
    } */

    //Does the same as above
    //Put in a loop so everyone gets/does it
    //MPI_Reduce(&localdot, &dotproduct, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    //OR
    MPI_AllReduce(&localdot, &dotproduct, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if(my_rank == 0)
        cout << dotproduct << endl;

    delete [] a;
    delete [] b;
    delete [] local_a;
    delete [] local_b;

 
	// Shut down MPI
	MPI_Finalize();

	return 0;
}