#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mpi.h" // message passing interface
using namespace std;

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah

int main(int argc, char *argv[])
{

	int my_rank;	   // my CPU number for this process
	int p;			   // number of CPUs that we have
	int source;		   // rank of the sender
	int dest;		   // rank of destination
	int tag = 0;	   // message number
	char message[100]; // message itself
	MPI_Status status; // return status for receive

	// Start MPI
	MPI_Init(&argc, &argv);

	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	// Find out the number of processes!
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	// THE REAL PROGRAM IS HERE
	srand(1231);

	//Know the problem (PREFIX SUM)

	int n = 300000;
	int *a = new int[n];
	long *psum = new long[n];

	/*
	for (int x = 0; x < n; x++)
		a[x] = rand() % 8;

	psum[0] = a[0];
	for (int x = 1; x < n; x++)
		psum[x] = psum[x - 1] + a[x];
*/

	//Do the local work

	if (my_rank == 0)
		for (int x = 0; x < n; x++)
			a[x] = rand() % 8;

	//Divide the problem up
	int *locala = new int[n / p];
	long *localpsum = new long[n / p];

	MPI_Scatter(&a[0], n / p, MPI_INT, locala, n / p, MPI_INT, 0, MPI_COMM_WORLD);

	localpsum[0] = locala[0];
	for (int x = 1; x < n / p; x++)
		localpsum[x] = localpsum[x - 1] + a[x];

	//Send my last partial prefix sum answer to all LATER processors
	for (int x = my_rank + 1; x < p; x++)
		MPI_Send(&localpsum[n/p - 1], 1, MPI_LONG, x, tag, MPI_COMM_WORLD);

	long localadditive = 0;
	long localtemp = 0;
	//Wait to receive my stuff from the guys behing me
	for (int x = 0; x < my_rank; x++)
	{
		MPI_Recv(&localtemp, 1, MPI_LONG, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
		localadditive += localtemp;
	}

	//Add additive across local arrays
	for(int x = 0; x < n/p; x++)
		localpsum[x] += localadditive;

	//COLLECT THE ANSWERS BACK TOGERTHER IN A HAPPY ENDING
	MPI_Gather(&localpsum[0], n/p, MPI_LONG, psum, n/p, MPI_LONG, 0, MPI_COMM_WORLD);

	if(my_rank == 0)
		for (int x = 0; x < n; x++)
			cout << a[x] << " ";
	cout << endl;


	// Shut down MPI
	MPI_Finalize();

	delete[] a;
	delete[] psum;
	delete[] locala;
	delete[] localpsum;

	return 0;
}