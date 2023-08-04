#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (rear == MAX_SIZE - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int dequeuedValue = queue[front];
    front++;

    if (front > rear) {
        front = rear = -1; // Reset front and rear when the queue becomes empty.
    }

    return dequeuedValue;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    int dequeued = dequeue();
    if (dequeued != -1) {
        printf("Dequeued element: %d\n", dequeued);
    }
    display();

    return 0;
}
