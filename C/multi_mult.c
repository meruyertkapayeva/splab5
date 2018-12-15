// your code goes here
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 100

int a[N][N];
int b[N][N];
int c[N][N];
int n=2;
int sum=0;

struct data{int summ; int size; int i; int j;
};

void* Add(void* p){
	struct data* name= (struct data*) p;
	int i=name->i;
	int l=name->j;
	int k=name->size;
        int sum=name->summ;
	int sa;
	
	for(int sa=0;sa<k;sa++){
			sum=sum+a[i][sa]*b[sa][l];
		}
	c[i][l]=sum;
	

	pthread_exit(NULL);
}



int main(int argc, char* argv[]){
if(argc>1){
  n=atoi(argv[1]);} 
else n=2;

srand(time(0));
int i,j,k;
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
     a[i][j]=rand()%100;
     b[i][j]=rand()%100;
}}

pthread_t t[N][N];
struct data s[N][N];

int count=0;
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
     s[i][j].summ=0;
     s[i][j].size=n;
     s[i][j].i=i;
     s[i][j].j=j;
     count++;
     printf("%d",count );
     pthread_create(&t[i][j],NULL,Add,(void*)&s[i][j]);
}}

for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
     pthread_join(t[i][j],NULL);
}}

printf("A:\n");
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
     printf("%d ",a[i][j]);
  }
  printf("\n");
}

printf("B:\n");
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
     printf("%d ",b[i][j]);}
printf("\n");
}

printf("C:\n");
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
     printf("%d ", c[i][j]);
}
printf("\n");
}


pthread_exit(NULL);}
