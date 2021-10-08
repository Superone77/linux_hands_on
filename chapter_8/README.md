### 《Linux编程实战》第八章OpenMP程序设计基础

Ubuntu:

gcc -g -Wall -fopenmp mp-hello.c -o mp-hello

MacOS:

brew install libomp  
clang -Xpreprocessor -fopenmp -lomp mp-hello.c
***
兼容性检查例子：check.c

clang -Xpreprocessor -fopenmp -lomp check.c  
./a.out 4  
rm -rf a.out  
 
clang check.c 
./a.out 4  

***

最常用的三个库函数：（mp-hello-fn.c）  
int omp_get_num_threads(void);//获取当前线程组的线程数量，如果不在并行区调用返回1   
int omp_get_thread_num(void);//返回当前线程号    
int omp_get_num_procs(void);//返回可用的处理核个数   

./a.out 4
结果：
```
proc count 8 
thread count 1 
Thread 0 says hello to you! 
thread count 4 
Thread 1 says hello to you! 
thread count 4 
Thread 2 says hello to you! 
thread count 4 
Thread 3 says hello to you! 
thread count 4 
thread count 1 
```
***



