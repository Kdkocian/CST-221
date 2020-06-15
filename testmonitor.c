//monitor testMonitor
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lockmechanism;

enum states
{
	waiting_tables, cleaning_tables
};

struct waiters
{
	enum states status;
	int waiter;
};

void cleaning(void* w)
{
	struct waiters *someperson = (struct waiters*)w;
	printf("waiter%d is cleaning a table\n",(*someperson).waiter);
	sleep(2);	
}

void monitor(void* m)
{
	pthread_mutex_lock(&lockmechanism);
	struct waiters *poodles = (struct waiters*)m;
	cleaning(poodles);
	pthread_mutex_unlock(&lockmechanism);	
}
void* waiting(void* t)
{
	struct waiter *someperson = (struct waiter*)t;
	while(1)
	{
		monitor(someperson);
	}
}
 int main()
 {
 	struct waiters *cody = malloc(sizeof(struct waiters));
 	(*cody).status = waiting_tables;
 	(*cody).waiter = 0;
 	pthread_t poodle1;
 	pthread_create(&poodle1, NULL, waiting, (void*) cody);
 	
 	struct waiters *brenda = malloc(sizeof(struct waiters));
 	(*brenda).status = waiting_tables;
 	(*brenda).waiter = 1;
 	pthread_t poodle2;
 	pthread_create(&poodle2, NULL, waiting, (void*) brenda);
 	
 	pthread_join(poodle1, NULL);
 	pthread_join(poodle2, NULL);
 	
 	return 0;
 }	
