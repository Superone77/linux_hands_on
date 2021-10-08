#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int num_t = strtol(argv[1],NULL,10);//将字符串转换为长整型数(long)
    printf("The serial program says hello to you with input %d!\n", num_t);
    return 0;
}