#include <stdio.h>
#include <unistd.h>

void print_arr(unsigned char*, int);

int main(){
    FILE* file = fopen("./teapot.bmp", "rb+");
    if (file == NULL) return -1;
    unsigned char header[200];
    fread(header,sizeof(header[0]), 27,file);
    if (header[0]!= 0x42 && header[1] != 0x4d) return -1;
    int len = *((int*) (header+2));
    int offset = *((int*) (header+10));
    int width = *((int*) (header+18));
    int height = *((int*) (header+22));
    unsigned char image[height][width*3];
    fread(header,sizeof(header[0]), 27,file);
    




    printf("Length: %d Offset: %d Height: %d Width: %d, Total: %d\n", len, offset,height,width,height*width*3);
    print_arr(header,22);
    fclose(file);
}

void print_arr(unsigned char* arr, int size){
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%x ", arr[i]);
    }
    printf("\n");
}