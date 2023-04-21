#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    int FILE = open("./text.txt",O_WRONLY);
    lseek(FILE,0,SEEK_END);
    while(1){
        printf("Write: ");
        char input[1000];
        fgets(input,100,stdin);
        int i = 0;
        for (; i < 10000 && input[i]; i++)
            ;
        char* str = malloc(i);
        for (int j = 0; j < i; j++){
            str[j] = input[j];
        }

        write(FILE,str,i);
        struct stat buf;
        fstat(FILE,&buf);

        printf("\nWrite complete \nInode: %d File Size: %d Blocks: %d\n\n", (int) buf.st_ino, (int) buf.st_size, (int) buf.st_blocks);

    }
    close(FILE);
}