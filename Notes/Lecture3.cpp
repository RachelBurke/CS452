#include <iostream>
#include <stdio.h>
#include <string.h>
#include <mpi.h> // message passing interface
using namespace std;

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah

int main(int argc, char *argv[])
{

    int my_rank;       // my CPU number for this process
    int p;             // number of CPUs that we have
    int source;        // rank of the sender
    int dest;          // rank of destination
    int tag = 0;       // message number
    char message[100]; // message itself
    MPI_Status status; // return status for receive

    // Start MPI
    MPI_Init(&argc, &argv);

    // Find out my rank!
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // Find out the number of processes!
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    // THE REAL PROGRAM IS HERE

    // Basic
    // Add numbers from one to 300000
    //int sum = 0;
    //for (int x = 0; x < 300000; x++)
    //    sum += x;
    //cout << sum << endl;

    // Parallel
    /*
        //Blocking
        // KNOW WHAT THE PROBLEM IS
        int n = 300000;
        long sum = 0;

        // BREAK THE PROBLEM UP INTO PIECES
        int local_start = n / p * my_rank;
        // EACH PROCESS DOES ITS OWN LOCAL WORK
        long long local_sum = 0;
        for (int x = local_start; x < local_start + n/p; x++)
            local_sum += x;
        // GLUE THOSE LOCAL RESULTS BACK TOGETHER
        // The processor in charge is called the overseer.
        // By convention the overseer is usually processs 0.

        //If I am not an overseer, send my answer to the overseer
        if (my_rank != 0)
            MPI_Send(&local_sum, 1, MPI_LONG_LONG_INT, 0, tag, MPI_COMM_WORLD);
        else{
            sum = local_sum;
            long long temp;
            for(int x = 1; x < p; x++) {
                MPI_Recv(&temp, 1, MPI_LONG_LONG_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
                sum += temp;
            } //end for
            cout << sum << endl;
        } //end else
    */
    /*
        //Striping
        // KNOW WHAT THE PROBLEM IS
        int n = 300000;
        long sum = 0;

        // BREAK THE PROBLEM UP INTO PIECES
        int local_start = my_rank;
        // EACH PROCESS DOES ITS OWN LOCAL WORK
        long long local_sum = 0;
        for (int x = local_start; x < n; x += p)
            local_sum += x;
        // GLUE THOSE LOCAL RESULTS BACK TOGETHER
        // The processor in charge is called the overseer.
        // By convention the overseer is usually processs 0.

        //If I am not an overseer, send my answer to the overseer
        if (my_rank != 0)
            MPI_Send(&local_sum, 1, MPI_LONG_LONG_INT, 0, tag, MPI_COMM_WORLD);
        else{
            sum = local_sum;
            long long temp;
            for(int x = 1; x < p; x++) {
                MPI_Recv(&temp, 1, MPI_LONG_LONG_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
                sum += temp;
            } //end for
            cout << sum << endl;
        } //end else
    */
    //MPI RELAY RACE
    // KNOW WHAT THE PROBLEM IS
    char *baton = message;
    sprintf(message, "Sent list: ");
    sprintf(baton + strlen(baton), % d, my_rank);

    if (my_rank == 0)
    {
        cout << "I HAVE THE BATON, SUCK IT! " << my_rank << endl;
        cout << "Run, process " << my_rank << " RUN!" << endl;
        MPI_Send(baton, strlen(baton) + 1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
        MPI_Recv(baton, 100, MPI_CHAR, p - 1, tag, MPI_COMM_WORLD, &status);
        cout << "Declare a provisional victory!" << endl;
        cout << baton << endl;
    } // end if
    else
    {
        MPI_Recv(baton, 100, MPI_CHAR, my_rank - 1, tag, MPI_COMM_WORLD, &status);
        sprintf(baton + strlen(baton), % d, my_rank);
        cout << baton << endl;
        cout << "Run, process " << my_rank << " RUN!" << endl;
        MPI_Send(baton, strlen(baton) + 1, MPI_CHAR, (my_rank +1) % p, tag, MPI_COMM_WORLD);
    } //end else

    // Shut down MPI
    MPI_Finalize();

    return 0;
}