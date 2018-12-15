# script that measures time
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int i;
void *calculate(void *data){
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t t[100];
	for(i = 0 ; i < 100 ; i++ ) {
		pthread_create(&t[i],NULL,&calculate,NULL);
	}
	for(i = 0 ; i < 100 ; i++ ) {
		pthread_join(t[i],NULL);
	}
	pthread_exit(NULL);
}


# !/bin/bash
gcc atask.c -o atask
time ./atask

gcc btask.c -o btask
time ./btask

gcc ctask.c -o ctask
time ./ctask
