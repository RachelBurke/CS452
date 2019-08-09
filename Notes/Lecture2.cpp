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
    cout << my_rank << endl;
    sprintf(message, "Yo shizzle my nizzle, %d, %d", my_rank, p);
    cout << message << endl;

    // Example 1
    // These three lines end in a deadlock 
    //MPI_Send(message, strlen(message)+1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
    //MPI_Recv(message, 100, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
    //cout << message << endl;

    // Example 2
    // This prints the lines we would expect
    //MPI_Send(message, strlen(message)+1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
    //if (my_rank == 1)
    //    MPI_Recv(message, 100, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
    //cout << message << endl;

    // Example 3
    // This should have 11 outputs (4 processes)
    //MPI_Send(message, strlen(message)+1, MPI_CHAR, 2, tag, MPI_COMM_WORLD);
    //if (my_rank == 2)
    //    for (int x = 0; x < p; x++) {
    //        MPI_Recv(message, 100, MPI_CHAR, x, tag, MPI_COMM_WORLD, &status);
    //        cout << message << endl;
    //    }
    //else
    //    cout << message << endl;

    // Basic
    // Add numbers from one to 300000
    //int sum = 0;
    //for (int x = 0; x < 300000; x++)
    //    sum += x;
    //cout << sum << endl;

    // Parallel
    // KNOW WHAT THE PROBLEM IS
    // BREAK THE PROBLEM UP INTO PIECES
    // EACH PROCESS DOES ITS OWN LOCAL WORK
    // GLUE THOSE LOCAL RESULTS BACK TOGETHER


	// Shut down MPI
	MPI_Finalize();

	return 0;
}