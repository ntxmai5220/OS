#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
	return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
	/* TODO: put a new process to queue [q] */
	if (q->size == MAX_QUEUE_SIZE)
		return;
	q->proc[q->size] = proc;
	q->size++;
}

struct pcb_t *dequeue(struct queue_t *q)
{
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0)
		return NULL;
	int sizeOfQueue = q->size;
	struct pcb_t *proc_priority = q->proc[0];
	int counter = 1;
	int ind_priority = 0;
	while (counter < sizeOfQueue)
	{
		if (q->proc[counter]->priority > proc_priority->priority)
		{
			proc_priority = q->proc[counter];
			ind_priority = counter;
		}
		counter++;
	}
	while (ind_priority < sizeOfQueue - 1)
	{
		q->proc[ind_priority] = q->proc[ind_priority + 1];
		ind_priority++;
	}
	delete (q->proc[ind_priority]);
	return proc_priority;
}
