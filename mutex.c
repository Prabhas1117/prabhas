#include<stdio.h>
#include<pthread.h>


pthread_mutex_t mutex;
int sum=0;
void *func1(void *args)
{
pthread_mutex_lock(&mutex);
sum = sum + (*(int*)args);
pthread_mutex_unlock(&mutex);
printf("%d\n",sum);

}

void *func2(void *num)
{
pthread_mutex_lock(&mutex);
sum = sum + (*(int*)num);
sum=sum/10;
pthread_mutex_unlock(&mutex);
printf("%d\n",sum);

}

int main()
{
pthread_mutex_init(&mutex,NULL);
pthread_t t1,t2;
int n1 = 10;
int n2 = 20;
pthread_create(&t1,NULL,func1,(void*)&n1);
pthread_create(&t2,NULL,func2,(void*)&n2);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_mutex_destroy(&mutex);

}
