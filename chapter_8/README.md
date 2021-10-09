### 《Linux编程实战》第八章OpenMP程序设计基础

Ubuntu:

gcc -g -Wall -fopenmp mp-hello.c -o mp-hello

MacOS:

brew install libomp  
clang -Xpreprocessor -fopenmp -lomp mp-hello.c
***
兼容性检查例子：[check.c](check.c)

clang -Xpreprocessor -fopenmp -lomp check.c  
./a.out 4  
rm -rf a.out  
 
clang check.c 
./a.out 4  

***

最常用的三个库函数：[mp-hello-fn.c](mp-hello-fn.c)    
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

[mp-acc1.c](mp-acc1.c)   
sum+=i是临界区（一段被多个更新共享资源的线程执行的代码），当两个更新同时进行时，会产生Lost Update的问题。

**OpenMP提供了三种不同类型的多线程同步机制：排它锁、原子操作和临界区**

[mp-acc2.c](mp-acc2.c)
**编译制导critical**声明一个临界区，临界区一次只允许一个线程执行。
但如此一来，程序实际上变为串行程序。

[mp-acc3.c](mp-acc3.c)
**变量作用域**
给每个线程定义一个求部分和的局部变量，然后对每个线程对部分和局部变量再求和。

[mp.acc4.c](mp-acc4.c)
可以使用default、shared、private子句来为变量指定作用域。  
shared说明该变量在共享作用域    
private说明该变量在每个线程中声明一个新对象   
firstprivate 说明该变量在每个线程开始时根据并行区外的值初始化   
lastprivate 子句指定的变量不仅是private作用范围，同时会将最后一次迭代或最后一个section执行的值复制回原来的变量    
default(none)时必须显式地为所有变量指定作用域    
default(shared)时没显式指定的变量都在共享作用域    

[mp-parallel-for.c](mp-parallel-for.c)  
parallel for用于生成一个并行域，并将计算任务在多个线程之间分配，从而加快计算运行的速度。可以让系统默认分配线程个数，也可以使用num_threads子句指定线程个数。

