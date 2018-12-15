// your code goes here
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a=0, b=0,r1=0, r2=0, r3=0, r4=0;

void *add(void *p){
 r1 = a+b; 
 pthread_exit(NULL);
}

void *sub(void *p){
 r2 = a-b; 
 pthread_exit(NULL);
}

void *mul(void *p){
 r3 = a*b; 
 pthread_exit(NULL);
}

void *divide(void *p){
 r4 = a/b;
 pthread_exit(NULL);
}

int main(int argc, char* argv[]){

 pthread_t t1,t2,t3,t4;

 a = atoi(argv[1]);
 b = atoi(argv[2]); 
pthread_create(&t1,NULL,add,NULL);
 pthread_create(&t2,NULL,sub,NULL);
 pthread_create(&t3,NULL,mul,NULL);
 pthread_create(&t4,NULL,divide,NULL);

 pthread_join(t1,NULL); 
 pthread_join(t2,NULL); 
 pthread_join(t3,NULL); 
 pthread_join(t4,NULL); 

 printf("Add: %d + %d = %d\n", a, b, r1);
 printf("Sub: %d - %d = %d\n", a, b, r2);
 printf("Mul: %d * %d = %d\n", a, b, r3);
 printf("Div: %d / %d = %d\n", a, b, r4);
 
 pthread_exit(NULL);
}
