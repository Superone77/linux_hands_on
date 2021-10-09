#include <stdio.h>
#include <stdlib.h>
#include <omp.h>//OpenMP程序需要加入该头文件

void test()
{
    for (int i = 0; i < 80000; i++)
    {
        i++;
        i--;
    }
}

int main()
{
    float startTime = omp_get_wtime();

    //指定两个线程
#pragma omp parallel for num_threads(2)
    for (int i = 0; i < 80000; i++)
    {
        test();
    }
    float endTime = omp_get_wtime();
    printf("指定 2 个线程，执行时间: %f\n", endTime - startTime);
    startTime = endTime;

    //指定4个线程
#pragma omp parallel for num_threads(4)
    for (int i = 0; i < 80000; i++)
    {
        test();
    }
    endTime = omp_get_wtime();
    printf("指定 4 个线程，执行时间: %f\n", endTime - startTime);
    startTime = endTime;

    //指定8个线程
#pragma omp parallel for num_threads(8)
    for (int i = 0; i < 80000; i++)
    {
        test();
    }
    endTime = omp_get_wtime();
    printf("指定 8 个线程，执行时间: %f\n", endTime - startTime);
    startTime = endTime;

    //指定12个线程
#pragma omp parallel for num_threads(12)
    for (int i = 0; i < 80000; i++)
    {
        test();
    }
    endTime = omp_get_wtime();
    printf("指定 12 个线程，执行时间: %f\n", endTime - startTime);
    startTime = endTime;

    //不使用OpenMP
    for (int i = 0; i < 80000; i++)
    {
        test();
    }
    endTime = omp_get_wtime();
    printf("不使用OpenMP多线程，执行时间: %f\n", endTime - startTime);
    startTime = endTime;

    return 0;

}
