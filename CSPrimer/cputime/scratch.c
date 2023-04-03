#include <time.h>
#include <stdio.h>

int main () {
	struct timespec res;
	clock_getres(CLOCK_MONOTONIC_RAW, &res);
	printf("%ld sec %ld nsec\n", res.tv_sec, res.tv_nsec);
}
