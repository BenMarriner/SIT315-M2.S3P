#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <omp.h>


using namespace std::chrono;
using namespace std;

#define NUM_THREADS 12

void randomVector(int vector[], int size)
{
#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < size; i++)
        {
            //ToDo: Add Comment
            vector[i] = rand() % 100;
        }
    }
}


int main(){

    omp_set_dynamic(0);
    omp_set_num_threads(NUM_THREADS);

    unsigned long size = 100000000;

    srand(time(0));

    int *v1, *v2, *v3;

    //ToDo: Add Comment
    auto start = high_resolution_clock::now();

    //ToDo: Add Comment
    v1 = (int *) malloc(size * sizeof(int *));
    v2 = (int *) malloc(size * sizeof(int *));
    v3 = (int *) malloc(size * sizeof(int *));


    randomVector(v1, size);

    randomVector(v2, size);


    //ToDo: Add Comment
#pragma omp parallel
    {
#pragma omp for 
        for (int i = 0; i < size; i++)
        {
            v3[i] = v1[i] + v2[i];
        }
    }

    auto stop = high_resolution_clock::now();

    //ToDo: Add Comment
    auto duration = duration_cast<microseconds>(stop - start);


    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    //cout << "Used " << omp_get_num_threads() << " threads" << endl;

    return 0;
}