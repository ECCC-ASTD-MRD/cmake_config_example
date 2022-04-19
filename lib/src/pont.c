#include <stdio.h>
#include <omp.h>

#include "pont.h"

void printOmpNumThreads() {
#ifdef _OPENMP
    printf("OMP_NUM_THREADS=%d\n", omp_get_num_threads());
#else
    printf("Not built with OpenMP support!\n");
#endif
}
