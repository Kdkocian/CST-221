#include <pthread.h>
#include <stdio.h>
#include <stddef.h>
#include <sched.h>
#include <unistd.h>

int productCount = 0;
#define BUFFER_SIZE 10
void *producer()
{
	while (1)
	{
		if (productCount >= 10)
		{
			sleep(2);
		}
		productCount = productCount + 1;
		
	}
}

void consume(int productCount)
{
	printf("productCount : %d\n", productCount);
}
		
void consumer()
{
	while(1)
	{
		if(productCount == 0)
		{
			sleep(3);
		}
		productCount = productCount - 1;
		consume(productCount);
	}
}



int main()
{
	pthread_t pcThread;
	pthread_create (&pcThread, NULL, producer, NULL);
	consumer();
	return 0;
}
