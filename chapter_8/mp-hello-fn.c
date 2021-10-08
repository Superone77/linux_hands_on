#include <stdio.h>
#include <stdlib.h>
#include <omp.h>//OpenMP程序需要加入该头文件

int main(int argc, char* argv[]){
    int num_t = strtol(argv[1], NULL,10);//线程数
    //不在并行区调用：
    printf("proc count %d \n",omp_get_num_procs());//8核
    printf("thread count %d \n", omp_get_num_threads());

# pragma omp parallel num_threads(num_t)//编译制导语句
    {
        printf("Thread %d says hello to you! \n", omp_get_thread_num());
        printf("thread count %d \n", omp_get_num_threads());
    }
    //不在并行区调用
    printf("thread count %d \n", omp_get_num_threads());

    return 0;
}