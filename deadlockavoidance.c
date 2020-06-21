// Kyle Kocian
// CST-221
// Professor Michael Landreth
// 6/21/2020
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
// process varibles
pthread_t cheese;
pthread_t newThread;
pthread_mutex_t resource;

// process trying to lock resource
void* process(void* args)
{
	int timer = 0;
	timer++;
	printf("process %d Acquired the resource \n", *((int*)args));
	sleep(5);
	while(!pthread_mutex_trylock(&resource))
	{	
		printf("process %d failed to lock the resource \n", *((int*)args));
		if (timer >= 1)
		{
			printf("process %d exiting and has timed out \n", *((int*)args));
			exit(1);
		} 
		else 
		{
		sleep(2);
		}
	}
	printf("process %d releasing lock \n", *((int*)args));
	pthread_mutex_unlock(&resource);		
}
// creates and joins all threads
int main()
{
	int *thread1 = malloc(sizeof(*thread1));
	*thread1 = 1;
	int *thread2 = malloc(sizeof(*thread2));
	*thread2 = 2;
	pthread_create(&cheese, NULL, process, thread1);
	pthread_create(&newThread, NULL, process, thread2);
	pthread_join(cheese, NULL);
	pthread_join(newThread, NULL);
return 0;
}
