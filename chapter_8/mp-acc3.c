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
        //声明局部和
        int localsum=0;
        //求解局部和
        for(int i = item*id+1; i<=(id==count_t-1?max_num:item*(id+1));i++)
            localsum+=i;
            //声明临界区
#pragma omp critical
        //加在总和中
        sum+=localsum;
        printf("Thread %d & localsum %d & Sum %d\n",id,localsum,sum);
    }
    printf("sum %d\n", sum);
    return 0;
}


//./a.out 100 7
//Thread 0 & localsum 105 & Sum 105
//Thread 3 & localsum 693 & Sum 798
//Thread 1 & localsum 301 & Sum 2485
//Thread 4 & localsum 889 & Sum 2184
//Thread 6 & localsum 1480 & Sum 3965
//Thread 5 & localsum 1085 & Sum 5050
//Thread 2 & localsum 497 & Sum 1295
//sum 5050
//./a.out 100 8
//Thread 0 & localsum 78 & Sum 78
//Thread 4 & localsum 654 & Sum 732
//Thread 6 & localsum 942 & Sum 3520
//Thread 2 & localsum 366 & Sum 1098
//Thread 7 & localsum 1480 & Sum 2578
//Thread 1 & localsum 222 & Sum 3742
//Thread 3 & localsum 510 & Sum 5050
//Thread 5 & localsum 798 & Sum 4540
//sum 5050
// ./a.out 100 2
//Thread 0 & localsum 1275 & Sum 1275
//Thread 1 & localsum 3775 & Sum 5050
//sum 5050