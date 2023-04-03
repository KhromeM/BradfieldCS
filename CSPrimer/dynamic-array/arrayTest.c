#include <stdio.h>

void print_array_sq(int arr[], int size){
    for (int i = 0; i < size; i++){
        arr[i] *= arr[i];
        printf("%d " , arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[5] = {1,2,3,4,5};
    print_array_sq(arr, 5);
    for (int i = 0; i < 5; i++){
        printf("%d " , arr[i]);
    }

}