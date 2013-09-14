#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <sys/time.h>
#include "simd_copy.h"

void arrayCopy(void *dst, void *src, int nbytes){	
	int arraySize = nbytes/4;
	
	int * idst=(int*)dst;
	int * isrc=(int*)src;
		
	for(int i=0;i<arraySize;i++)
    {
		idst[i] = isrc[i];
    }
}

int main(int argc, char *argv[]){
	struct timeval tv1;
	struct timeval tv2;

	int arraySize = atoi(argv[1]);
	int numBytes = arraySize*4;
	
	int* sourceArray = new int[arraySize];
	int destArray[arraySize];

	for(int i=0; i<arraySize; i++){
		sourceArray[i] = i;
	}
	
	arrayCopy(destArray, sourceArray, numBytes);
	arrayCopy(destArray, sourceArray, numBytes);
	arrayCopy(destArray, sourceArray, numBytes);
	
	switch(atoi(argv[2])){
		case 1: { //my copy method
			gettimeofday(&tv1, 0);
			arrayCopy(destArray, sourceArray, numBytes);
			gettimeofday(&tv2, 0);
	
			double elapsed = (tv2.tv_sec + 1e-6 * tv2.tv_usec) - (tv1.tv_sec + 1e-6 * tv1.tv_usec);
			printf("%f \n", elapsed);
			break;
		}
		
		case 2: { //simd copy method
			gettimeofday(&tv1, 0);
			simd_memcpy(destArray, sourceArray, numBytes);
			gettimeofday(&tv2, 0);
	
			double elapsed = (tv2.tv_sec + 1e-6 * tv2.tv_usec) - (tv1.tv_sec + 1e-6 * tv1.tv_usec);
			printf("%f \n", elapsed);
			break;
		}
		
		case 3: { //simd_cache copy method
			gettimeofday(&tv1, 0);
			simd_memcpy_cache(destArray, sourceArray, numBytes);
			gettimeofday(&tv2, 0);
	
			double elapsed = (tv2.tv_sec + 1e-6 * tv2.tv_usec) - (tv1.tv_sec + 1e-6 * tv1.tv_usec);
			printf("%f \n", elapsed);
			break;
		}
	}
}