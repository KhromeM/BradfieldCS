#include <stdio.h>

void printBS(int test){
    switch (test) {
        case 1: printf("Option 1\n");
                printf("Some more blabber\n");
                break;
        case 2: printf("Option 2\n");
                printf("Some more blabber\n");
                break;
        case 3: printf("Option 3\n");
                printf("Some more blabber\n");
                break;
        case 4: printf("Option 4\n");
                printf("Some more blabber\n");
                break;
        case 5: printf("Option 5\n");
                printf("Some more blabber\n");
                break;
    }
}

int main(){
    int arr[3];
    for (int i = 3; i >= 0; i--){
        arr[i] = 10;
        printf("%d\n", &i);

    }

}