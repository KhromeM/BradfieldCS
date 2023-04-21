#include <stdio.h>
void overflow(int depth){
    printf("Depth: %d, Stack address: %p\n", depth,&depth);
    overflow(depth+1);
}

int main(){
    // overflow(0);
    int a = 0x12345678;
    long b = 0x1234567812345678;
    printf("%p %p %p", a,b, &b);

}