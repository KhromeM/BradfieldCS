#include <time.h>
#include <stdio.h>
#include <sys/time.h>

int main () {
	struct timeval t;
	gettimeofday(&t,NULL);
	printf("Time: %d\n", t.tv_sec);
	sleep(5);
	gettimeofday(&t, NULL);
	printf("Time: %d\n", t.tv_sec);


}
