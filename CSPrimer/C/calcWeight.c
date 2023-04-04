#include <stdio.h>

int main(){
    int height, width, length;
    printf("Height: ");
    scanf("%d", &height);
    printf("Width: ");
    scanf("%d", &width);
    printf("Length: ");
    scanf("%d", &length);
    printf("\nVolume: %d", height * width * length);
}