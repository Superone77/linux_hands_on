#include <stdio.h>
#include <stdlib.h>
#include <omp.h>//OpenMP程序需要加入该头文件

//从1加到最大数
int main(int argc, char* argv[]){
    int max_num = strtol(argv[1], NULL,10);//最大数
    int num_t = strtol(argv[2],NULL,10);//使用多少个线程

    int sum=0;
    int item = max_num/num_t;//每个线程计算的数量

    //声明并行区
# pragma omp parallel num_threads(num_t)
    {
        int id = omp_get_thread_num();
        int count_t = omp_get_num_threads();
        for(int i = item*id+1; i<=(id==count_t-1?max_num:item*(id+1));i++)
            sum+=i;
        printf("Thread %d & Sum %d\n",id,sum);
    }
    printf("sum %d\n", sum);
    return 0;
}

//result:
// ./a.out 100 8
//Thread 0 & Sum 78
//Thread 7 & Sum 4442
//Thread 3 & Sum 1242
//Thread 2 & Sum 1608
//Thread 6 & Sum 2550
//Thread 5 & Sum 3348
//Thread 1 & Sum 4552
//Thread 4 & Sum 732
//sum 4552
// ./a.out 100 7
//Thread 0 & Sum 105
//Thread 3 & Sum 1687
//Thread 4 & Sum 994
//Thread 1 & Sum 1988
//Thread 2 & Sum 2485
//Thread 5 & Sum 3570
//Thread 6 & Sum 5050
//sum 5050
// ./a.out 100 1
//Thread 0 & Sum 5050
//sum 5050
