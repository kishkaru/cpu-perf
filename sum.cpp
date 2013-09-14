#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include "counters.h"

int main(int argc, char *argv[]){
	hwCounter_t c1;
	c1.init = false;
	initTicks(c1);
	
	printf("%s", argv[0]);

	//int n = atoi(argv[1]);
	long long sum = 0;

	uint64_t time = getTicks(c1);
	for(long long i = 0; i<10000; i++){
		sum+= i;
	}
	
	uint64_t elapsed = getTicks(c1) - time;
	printf("Elapsed time in ticks: %lu \n", elapsed);
	//printf("Sum: %lu \n", sum);
}
