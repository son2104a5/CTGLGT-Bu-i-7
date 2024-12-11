#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct {
    int priority;
    char data[50];
} QueueElement;

typedef struct {
    QueueElement elements[MAX_SIZE];
    int size;
} PriorityQueue;

void initializeQueue(PriorityQueue *queue) {
    queue->size = 0;
}

bool isEmpty(PriorityQueue *queue) {
    return queue->size == 0;
}

bool isFull(PriorityQueue *queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(PriorityQueue *queue, int priority, const char *data) {
    if (isFull(queue)) {
        printf("Hang doi da day, khong the them phan tu moi.\n");
        return;
    }

    int i = queue->size - 1;
    while (i >= 0 && queue->elements[i].priority < priority) {
        queue->elements[i + 1] = queue->elements[i];
        i--;
    }

    queue->elements[i + 1].priority = priority;
    strcpy(queue->elements[i + 1].data, data);
    queue->size++;

    printf("Them phan tu (%d, \"%s\"): Kich thuoc hang doi = %d\n", priority, data, queue->size);
}

void dequeue(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong, khong the xoa phan tu.\n");
        return;
    }

    QueueElement element = queue->elements[0];
    for (int i = 1; i < queue->size; i++) {
        queue->elements[i - 1] = queue->elements[i];
    }
    queue->size--;

    printf("Xoa phan tu co uu tien cao nhat: (%d, \"%s\")\n", element.priority, element.data);
}

void printQueue(PriorityQueue *queue) {
    printf("Trang thai hien tai cua hang doi: ");
    for (int i = 0; i < queue->size; i++) {
        printf("(%d, \"%s\") ", queue->elements[i].priority, queue->elements[i].data);
    }
    printf("\n");
}

int main() {
    PriorityQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 2, "Task A");
    printQueue(&queue);

    enqueue(&queue, 1, "Task B");
    printQueue(&queue);

    enqueue(&queue, 3, "Task C");
    printQueue(&queue);

    dequeue(&queue);
    printQueue(&queue);

    dequeue(&queue);
    printQueue(&queue);

    return 0;
}
