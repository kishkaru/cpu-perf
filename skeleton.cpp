#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include "counters.h"

int main(int argc, char *argv[]){
	hwCounter_t c1;
	c1.init = false;
	initTicks(c1);

	uint64_t curr_time = getTicks(c1);
	printf("Current time in ticks %lu \n", curr_time);
}
