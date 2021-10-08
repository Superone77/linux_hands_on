#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
# include <omp.h>//OpenMP程序需要加入该头文件
#endif

int main(int argc, char* argv[]){
    int num_t = strtol(argv[1], NULL,10);//线程数
    //int maxThreads = omp_get_max_threads();
    //printf("Max threads is %d.\n",maxThreads);

# pragma omp parallel num_threads(num_t)//编译制导语句
    {
#ifdef _OPENMP
        int rank_t = omp_get_thread_num();//返回当前的线程号
#else
        int rank_t = 0;
#endif
        printf("Thread %d says hello to you !\n", rank_t);
    }
    return 0;
}