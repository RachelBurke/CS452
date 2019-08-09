#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std; 

//
// Project 2
// A Minor Character Can Still Drink Heavily
// Rachel Burke
//

void mergesort(int * a, int first, int last);
void merge(int * a, int * b, int first, int last, int middle);
void print(int * a, int n);

int main(int argc, char*argv[])
{
    //Pseudo-random number generator seeded at 1251
    srand(1251);

    //Get the dynamic array a size for mergesort
    int n = 0;
    cout << "Size of array to sort: ";
    cin >> n;
    cout << endl;

    //Initalize the dynamic array
    int * a = new int[n];

    //Setting pseudo-random data in array a
    for(int i = 0; i < n; i++)
        a[i] = rand() % 1000000;

    //Print before
    print(a, n);

    //Mergesort
    mergesort(a, 0, n - 1);

    //Print result
    print(a, n);

    return 0;
}

void mergesort(int * a, int first, int last)
{
    if(last - first < 1)
        return;
    int middle = (first + last) / 2;
    int * b = new int [last - first + 1];
    mergesort(a, first, middle);
    mergesort(a, middle + 1, last);
    merge(a, b, first, last, middle);

    delete [] b;

    return;
}

void merge(int * a, int * b, int first, int last, int middle)
{   
    int i = first;
    int j = middle + 1;
    int k = 0;

    while(i <= middle && j <= last)
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];

    for(int x = i; x <= middle; x++)
        b[k++] = a[x];
    for(int x = j; x <= last; x++)
        b[k++] = a[x];

    //Copy back b into a
    for(int x = first; x <= last; x++)
        a[x] = b[x - first];

    return;
}

void print(int * a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return;
}