//Semaphorestest
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <string.h>

sem_t passenger;

void* car(void* arg)
{
	sem_wait(&passenger);
	int p = *((int*)arg);
	printf("%d entered the vehicle\n", p);
	sleep(3);
	printf("%d exited the vehicle\n", p);
	sem_post(&passenger);
}

int main()
{
	sem_init(&passenger, 0, 5);
	pthread_t threads[6];
	for(int p=0; p<6; p++)
	{
		int *arg = malloc(sizeof(*arg));
		*arg = p;
		pthread_create(&threads[0], NULL, car, arg);
	}
	
	for(int e=0; e<6; e++)
	{
		while(&passenger==0){};
		pthread_join(threads[e], NULL);
	}
	return 0;
}

