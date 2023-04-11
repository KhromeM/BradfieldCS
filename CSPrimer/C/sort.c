#include <stdio.h>
#include <stdlib.h>


int* merge(int*, int, int*, int);
int* merge_sort(int*, int);
void quicksort(int*, int, int);
void printArr(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {1,4,-2,4,7,29,4,6,0,-6,8,22,85,-4,0,3,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    // int* newArr = merge_sort(arr, size);
    printf("%d\n",size);
    quicksort(arr,0, size);
    printArr(arr, size);

    // printArr(newArr,size);
}

int* merge_sort(int* arr, int size){
    if (size <= 1){
        return arr;
    }
    int* first_half = merge_sort(arr, size / 2);
    arr += size / 2;
    int* sec_half = merge_sort(arr, size / 2 + size % 2);
    int* result = merge(first_half, size / 2, sec_half, size / 2 + size % 2);
    if (size == 3){
        free(sec_half);
    } else if (size > 3){
        free(first_half);
        free(sec_half);
    }
    return result;
}

int* merge(int* first_half, int fsize, int* sec_half, int ssize){
    int* new_arr = malloc(sizeof(int) * (fsize + ssize));
    int p1 = 0, p2 = 0, i = 0;
    while (p1 < fsize && p2 < ssize) {
        if (first_half[p1] <= sec_half[p2]){
            new_arr[i++] = first_half[p1++];
        } else{
            new_arr[i++] = sec_half[p2++];
        }
    }
    while (p1 < fsize) new_arr[i++] = first_half[p1++];
    while (p2 < ssize) new_arr[i++] = sec_half[p2++];
    
    return new_arr;
}

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void quicksort(int* arr, int start, int end){
    if (start == end) return;
    int pivot = rand() % (end - start) + start;
    swap(arr+pivot, arr+end-1);
    int before = start;
    for (int i = start; i < end; i++){
        if (arr[i] <= arr[end-1]) {
            swap(arr+i, arr+before);
            before++;
        }
    }
    quicksort(arr, start, before-1);
    quicksort(arr,before,end);
}