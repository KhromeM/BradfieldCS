#include <stdio.h>
#include <unistd.h>

int main(){
    unsigned int n;
    while (1){
        printf("\nEnter a number: ");
        scanf("%d", &n);
        if (n == 0) break;
        printf(" %d\n", n);
        for (int i = 0; i < n; i++) {
            printf("%c",7);
            usleep(100000);
        }
    }
}