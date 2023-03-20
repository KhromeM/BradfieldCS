#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>


int bitcount(unsigned int n){
    int ans = 0;
    while (n) {
        ans++;
        n &= (n-1);
    }
    return  ans;
}

int isPangram(char *line, int len){
    int bitset = 0;
    for (int i = 0; i < len; i++){
        char c = tolower(*(line+i));
        if (c < 'a' || c > 'z') continue;
        bitset |= 1 << (c - 'a');
    }
    return bitset == 0x03ffffff;
}

int main(){
    // Exercise 2: Bitcount
    // int arr[] = {0,1,2,3,4,5,6,7,8,9,0xffffffff};
    // for (int i = 0; i < 11; i++){
    //     printf("%d has %d ones\n", arr[i], bitcount(arr[i]));
    // }

    // Exercise 3: Fast Pangram
    // FILE *text = fopen("./fast-pangram/cases.txt","r");
    // char *line = NULL;
    // ssize_t len = 0;
    // while(getline(&line,&len,text) != -1){
    //     if (isPangram(line,len))
    //         printf("%s", line);
    // }
    // fclose(text);
    // if (line)
    //     free(line);

    
    return 0;
}