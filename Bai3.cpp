#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
	int array[MAX];
	int front;
	int rear;
} Queue;

void initial(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

int isFull(Queue* queue){
	if(queue->rear >= MAX - 1){
		return 1;
	}
	return 0;
}

void enqueue(Queue* queue, int value){
	if(isFull(queue)){
		printf("Hang doi da day, khong them duoc!");
		return;
	}
	if(isEmpty(queue)){
		queue->front = 0;
	}
	queue->rear++;
	queue->array[queue->rear] = value;
}

void dequeue(Queue* queue){
	int temp;
	if(isEmpty(queue)){
		printf("Hang doi rong!");
		return;
	}
	temp = queue->array[queue->front];
	queue->front = queue->front + 1;
	printf("Phan tu da xoa: %d\n", temp);
}

void displayQueue(Queue* queue){
	printf("Hang doi sau khi cap nhat: ");
	for(int i = queue->front; i <= queue->rear; i++){
		printf("%d\t", queue->array[i]);
	}
}

int main(){
	Queue queue;
	initial(&queue);
	int value, n;
	printf("n = ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &value);
		enqueue(&queue, value);
	}
	dequeue(&queue);
	displayQueue(&queue);
	return 0;
}

