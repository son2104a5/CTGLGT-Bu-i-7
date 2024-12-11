#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Deque;

void initializeDeque(Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
    deque->size = 0;
}

bool isEmpty(Deque *deque) {
    return deque->size == 0;
}

bool isFull(Deque *deque) {
    return deque->size == MAX_SIZE;
}

void addFront(Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Hang doi da day, khong the them vao dau.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->data[deque->front] = value;
    deque->size++;
    printf("Them phan tu vao dau: %d\n", value);
}

void addRear(Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Hang doi da day, khong the them vao cuoi.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->data[deque->rear] = value;
    deque->size++;
    printf("Them phan tu vao cuoi: %d\n", value);
}

void removeFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong, khong the xoa tu dau.\n");
        return;
    }

    printf("Lay ra phan tu tu dau: %d\n", deque->data[deque->front]);

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    deque->size--;
}

void removeRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong, khong the xoa tu cuoi.\n");
        return;
    }

    printf("Lay ra phan tu tu cuoi: %d\n", deque->data[deque->rear]);

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->size--;
}

void printDeque(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Trang thai hien tai cua hang doi: ");
    int i = deque->front;
    for (int count = 0; count < deque->size; count++) {
        printf("%d ", deque->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Deque deque;
    initializeDeque(&deque);

    addFront(&deque, 10);
    printDeque(&deque);

    addRear(&deque, 20);
    printDeque(&deque);

    addRear(&deque, 5);
    printDeque(&deque);

    removeFront(&deque);
    printDeque(&deque);

    removeRear(&deque);
    printDeque(&deque);

    return 0;
}

