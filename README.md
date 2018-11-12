## splab5 - pthreads basics

### Aim
- To get familiar with Pthread API

## TASK A: MATHREADS
Write a program `mathreads.c` and compile it as `mathreads`. The program should accept **two** arguments, create **four** threads. Each of the threads should perfom an arithmetic operation over the arguments (like addition, subtraction, multiplication or division) as shown below. Main thread should wait for its child threads and print the result. Child threads don't print anything, they just calculate the results.

```
$ gcc mathreads.c -o mathreads -lpthread
$ ./mathreads 3 5
add: 3+5=8
mul: 3*5=15
sub: 3-5=-2
div: 3/5=0
```

## TASK B: SINGLE THREADED MATRIX MULTIPLICATION
Write a program `single_mult.c` that will take size __`n`__ of a matrix as command line argument, will create 2 matrices, `A` and `B`, of size `n` by `n` with random values. Then it will multilply `A` and `B`, store the result in `C`.

```
$ gcc single_mult.c -o single_mult
$ ./single_mult 2
A:
1 2
3 4

B:
2 1
0 1

C:
2 3
6 7
```

## TASK C: MULTITHREADED MATRIX MULTIPLICATION 
Write program that does the same task as in the previous task but each element `C[i][j]` should be calculated by a separate thread.

```
$ gcc multi_mult.c -o multi_mult
$ ./multi_mult 2
A:
1 2
3 4

B:
2 1
0 1

C:
2 3
6 7
```

## TASK D: MEASUREMENT

1. measure running time of `TASK A`, and running time of similar task `DOMATH` of `splab2`. Compare them.
2. measure running time of `TASK B`, and running time of `TASK C`. Compare them.
3. measure the time of creating `100` threads (using `pthread_create`) vs `100` processes (using `fork`). Main/parent thread/process should `pthread_join`/`wait` all child threads/processes. Processes/threads don't do any jobs, just `exit`/`pthread_exit` successfully.
