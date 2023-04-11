#include <stdio.h>
#include <math.h>

int main(){
    double d = NAN;
    char* c = (char*)&d;
    char* message = "hello";
    for (int i = 0; i < 6; i++){
        c[i] = message[i];
    }
    for (int i = 0; i < 6; i++){
        printf("%c", c[i]);
    }
    printf("\n%lf\n",  d);

}