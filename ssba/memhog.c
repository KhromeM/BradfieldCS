#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    int n  = 1000000;
    char* s;
    printf("PID: %d\n", (int) getpid());
    while (n){ // allocates 1TB
        n--;
        s = malloc(1000000); // allocates 1 MB
        usleep(10);
        
    }
    printf("Done");
}