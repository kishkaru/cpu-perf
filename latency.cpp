#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <math.h>
#include "counters.h"

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	int theArray[n];

	for(int i=0; i<n; i++){
		theArray[i] = i;
	}
	
	srand(time(NULL));
	for(int i=n-1; i>0; i--){
		int x = rand() % i; //pick a number from [0...i-1]
		
		int temp = theArray[i];
		theArray[i] = theArray[x];
		theArray[x] = temp;
	}
	
	int index = 0;
	
	hwCounter_t c1;
	c1.init = false;
	initTicks(c1);
	
	uint64_t time = getTicks(c1);
	for(int i=0; i< pow(2,20); i++){
		index = theArray[index];
	}
	
	uint64_t elapsed = getTicks(c1) - time;
	printf("%lu \n", elapsed);
	
}