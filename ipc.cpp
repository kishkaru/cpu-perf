#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
#include "counters.h"

void opt_simd_sgemm(float *Y, float *A, float *B, int n);
void opt_scalar1_sgemm(float *Y, float *A, float *B, int n);
void opt_scalar0_sgemm(float *Y, float *A, float *B, int n);
void naive_sgemm(float *Y, float *A, float *B, int n);

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	struct timeval tv1;
	struct timeval tv2;
	
	hwCounter_t c1;
	hwCounter_t c2;
	c1.init = false;
	c2.init = false;
	initInsns(c1);
	initTicks(c2);

	float* A = new float[n*n];
	float* B = new float[n*n];
	float* Y = new float[n*n];	
	
	uint64_t time = getTicks(c2);
	uint64_t count = getInsns(c1);
	
	gettimeofday(&tv1, 0);
	naive_sgemm(Y, A, B, n);
	gettimeofday(&tv2, 0);
	
	uint64_t elapsed = getTicks(c2) - time;
	uint64_t executed = getInsns(c1) - count;
	double elapsed2 = (tv2.tv_sec + 1e-6 * tv2.tv_usec) - (tv1.tv_sec + 1e-6 * tv1.tv_usec);

	
	delete [] A;
	delete [] B;
	delete [] Y;

	printf("Executed instructions : %lu \n", executed);
	printf("Elapsed time in cycles: %lu \n", elapsed);
	printf("%f \n", elapsed2);
	

}
